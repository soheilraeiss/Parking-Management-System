#include "ParkingManagement.h"
#include <QDebug>
#include <iostream>
#include <string>
using std::string;

ParkingManagement::ParkingManagement() : n_floor(0), n_number(0)
{
    homePath = QDir::homePath() + "/parking_logs"; // Initialize home path
    QDir().mkpath(homePath);
    get_information();

    ParkingVIP p_vip;
    ParkingNormal p_normal;
    ParkingDaily p_daily;

    qInfo() << "*********************************Welcome*********************************" << Qt::endl;

    start(&p_normal, &p_vip, &p_daily);
}
//***********************************************************************
ParkingManagement::~ParkingManagement()
{
}
//*********************************************************************************************
int ParkingManagement::getN_floor() const
{
    return n_floor;
}
//***********************************************************************
void ParkingManagement::setN_floor(int newN_floor)
{
    n_floor = newN_floor;
}
//*********************************************************************************************
int ParkingManagement::getN_number() const
{
    return n_number;
}
//***********************************************************************
void ParkingManagement::setN_number(int newN_number)
{
    n_number = newN_number;
}
//*********************************************************************************************
void ParkingManagement::get_information()
{
    int num;
    qInfo() << "                    Please enter your parking details." << Qt::endl << Qt::endl;
    qInfo() << "Please enter the number of floors: ";
    std::cin >> num;
    setN_floor(num);
    qInfo() << "Please enter the capacity of parking: ";
    std::cin >> num;
    setN_number(num);
}
//*********************************************************************************************
void ParkingManagement::start(ParkingNormal *p_normal, ParkingVIP *p_vip, ParkingDaily *p_daily)
{
    while(true)
    {
        int answer;
        qInfo() << "Please choose one of them: " << Qt::endl;
        qInfo() << "1_ manager" << Qt::endl << "2_ user(entry)" << Qt::endl << "3_ user(exit)" << Qt::endl << "4_ change datails and increas credit" << Qt::endl << "5_ quit" << Qt::endl;
        std::cin >> answer;
        if (answer == 2)
        {
            user_entry(p_normal, p_vip, p_daily);
        }
        else if(answer == 3)
        {
            user_exit(p_normal, p_vip, p_daily);
        }
        else if(answer == 1)
        {
            manager(p_normal, p_vip, p_daily);
        }
        else if(answer == 4)
        {
            changes(p_normal, p_vip);
        }
        else
            return;
    }
}
//*********************************************************************************************
void ParkingManagement::user_entry(ParkingNormal *p_normal, ParkingVIP *p_vip, ParkingDaily *p_daily)
{
    int answer;
    char answer1;
    qInfo() <<"Have you registered before?(Y/N) " << Qt::endl;
    std::cin >> answer1;
    if (answer1 == 'Y')
    {
        string name, pass, id;
        int test;
        qInfo() << "Please enter your user name:" << Qt::endl;
        std::cin >> name;
        qInfo() << "Please enter your password:" << Qt::endl;
        std::cin >> pass;
        qInfo() << "Please enter your plate name:" << Qt::endl;
        std::cin >> id;

        test = p_vip->search(name, pass);
        if(test == -1)
        {
            p_normal->service(id);
            // Save normal user entry
            QStringList userData;
            userData << QString::fromStdString(name)
                     << QString::fromStdString(pass)
                     << QString::fromStdString(id)
                     << QDateTime::currentDateTime().toString();
            saveToCSV("normal_users_entry.csv", userData);
        }
        else {
            p_vip->service(test, id);
            // Save VIP user entry
            QStringList userData;
            userData << QString::fromStdString(name)
                     << QString::fromStdString(pass)
                     << QString::fromStdString(id)
                     << QDateTime::currentDateTime().toString();
            saveToCSV("vip_users_entry.csv", userData);
        }
    }
    else
    {
        qInfo() << "Do you want to sign up?(Y/N)" << Qt::endl << "if don't, you'll be daily user!" << Qt::endl;
        std::cin >> answer1;
        if(answer1 == 'Y')
        {
            qInfo() << "1_ VIP" << Qt::endl << "2_ Normal" << Qt::endl;
            std::cin >> answer;
            if (answer == 1)
            {
                p_vip->new_user();
                // Save new VIP user registration
                QStringList userData;
                userData << "New VIP User"
                         << QDateTime::currentDateTime().toString();
                saveToCSV("new_vip_users.csv", userData);
            }
            else
            {
                p_normal->new_user();
                // Save new normal user registration
                QStringList userData;
                userData << "New Normal User"
                         << QDateTime::currentDateTime().toString();
                saveToCSV("new_normal_users.csv", userData);
            }
        }
        else
        {
            p_daily->service();
            // Save daily user entry
            QStringList userData;
            userData << "Daily User"
                     << QDateTime::currentDateTime().toString();
            saveToCSV("daily_users.csv", userData);
        }
    }
}

//*********************************************************************************************
void ParkingManagement::user_exit(ParkingNormal *p_normal, ParkingVIP *p_vip, ParkingDaily *p_daily)
{
    std::string id;
    int test;
    qInfo() << "Please enter your plate number: " << Qt::endl;
    std::cin >> id;
    test = p_normal->search_current(id);

    QStringList exitData;
    exitData << QString::fromStdString(id)
             << QDateTime::currentDateTime().toString();

    if(test == -1)
    {
        test = p_daily->search_current(id);
        if(test == -1) {
            p_vip->exit(id);
            saveToCSV("vip_users_exit.csv", exitData);
        }
        else {
            p_daily->exit(test);
            saveToCSV("daily_users_exit.csv", exitData);
        }
    }
    else {
        p_normal->exit(test);
        saveToCSV("normal_users_exit.csv", exitData);
    }
}

//*********************************************************************************************
void ParkingManagement::manager(ParkingNormal *p_normal, ParkingVIP *p_vip, ParkingDaily *p_daily)
{
    while(true)
    {
        int answer;
        qInfo() << "Please choose one of the Services:" << Qt::endl;
        qInfo() << "1_ general report" << Qt::endl << "2_ current report" << Qt::endl << "3_ list of users" <<Qt::endl << "4_ income" << Qt::endl << "5_ quit" << Qt::endl;
        std::cin >> answer;
        switch (answer)
        {
        case 1:
            p_vip->printGeneralReport();
            break;
        case 2:
            printCurrentReport(p_normal, p_vip, p_daily);
            break;
        case 3:
            printUsers(p_normal, p_vip);
            break;
        case 4:
            qInfo() << p_vip->getIncome() << Qt::endl;
            break;
        case 5:
            return;
        }
    }
}
//*********************************************************************************************
void ParkingManagement::printUsers(ParkingNormal *p_normal, ParkingVIP *p_vip)
{
    p_normal->getUsers();
    p_vip->getUsers();
}
//*********************************************************************************************
void ParkingManagement::printCurrentReport(ParkingNormal *p_normal, ParkingVIP *p_vip, ParkingDaily *p_daily)
{
    p_daily->getCurrentUsers();
    p_normal->getCurrentUsers();
    p_vip->getCurrentUsers();
}
//*********************************************************************************************
void ParkingManagement::changes(ParkingNormal *p_normal, ParkingVIP *p_vip)
{
    int num;
    qInfo() << "what type of user are you? " << Qt::endl << "1_ nomal" << Qt::endl << "2_vip" << Qt::endl;
    std::cin >> num;
    if(num == 1)
        p_normal->change();
    else
        p_vip->change();
}
//*********************************************************************************************
// In ParkingManagement.cpp
void ParkingManagement::saveToCSV(const QString& filename, const QStringList& data) {
    QString fullPath = homePath + "/" + filename;
    QFile file(fullPath);

    // Create directory if it doesn't exist
    QFileInfo fileInfo(file);
    QDir().mkpath(fileInfo.path());

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << data.join(",") << "\n";
        file.close();
        qDebug() << "Data saved to:" << fullPath;
    } else {
        qDebug() << "Failed to open file:" << fullPath;
    }
}
void saveToCSV(const QString& filename, const QStringList& data) {
    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << data.join(",") << "\n";
        file.close();
    } else {
        qDebug() << "Failed to open file:" << filename;
    }
}

