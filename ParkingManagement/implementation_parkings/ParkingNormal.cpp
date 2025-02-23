#include "parkings/ParkingNormal.h"
#include <QDebug>
#include <iostream>

ParkingNormal::ParkingNormal()
{
    int num;
    qInfo() << "Please enter the number of normal users: ";
    std::cin >> num;
    setNumber(num);
    qInfo() << "Please enter the cost per hour: ";
    std::cin >> num;
    setCost(num);

}
//***********************************************************************
ParkingNormal::~ParkingNormal()
{
    /*for(int i = 0; i < users.size(); i++)
    {
        users[i]->~NormalUser();
    }*/

}
//*********************************************************************************************
void ParkingNormal::service(string id)
{
    if(i_normal == number)
    {
        qInfo() << "sorry, parking for normal users is full!" << Qt::endl;
        return;
    }
    int index, t = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i]->getCarID() == id || users[i]->getCar_2ID() == id)
        {
            index = i;
            t = 1;
            break;
        }
    }
    if(t == 0)
    {
        qInfo() << "sorry, you didn't registered!" << Qt::endl;
        return;
    }
    if(!users[index]->getCarID().empty() && !users[index]->getCar_2ID().empty())
    {
        if(users[index]->getCarID() == id)
        {
            string id_2 = users[index]->getCar_2ID();
            for (int i = 0; i < i_normal; i++)
            {
                if(normal[i]->current_ID == id_2)
                {
                    qInfo() << "sorry, your another car is in and you can't enter!" <<Qt::endl;
                    return;
                }
            }
        }
        else
        {
            string id_2 = users[index]->getCarID();
            for (int i = 0; i < i_normal; i++)
            {
                if(normal[i]->current_ID == id_2)
                {
                    qInfo() << "sorry, your another car is in and you can't enter!" <<Qt::endl;
                    return;
                }
            }
        }
    }
    if(users[index]->getMonthlyCredit() > 0)
    {
        users[index]->setEntryTime();
        qInfo() << "you can enter the parking!" << Qt::endl << users[index]->getEntryTime() << Qt::endl;
        report[users[index]->current_ID + "  entry"] = users[index]->getEntryTime();
        normal[i_normal] = users[index];
        i_normal++;
    }
    else
    {
        char answer;
        double credit;
        qInfo() << "sorry, you dont have enough credit!" << Qt::endl << "Do you want to recharge your credit?(Y/N)" << Qt::endl;
        std::cin >> answer;
        if(answer == 'Y')
        {
            qInfo() << "Please pay at least $100: " << Qt::endl;
            std::cin >> credit;
            users[index]->setMonthlyCredit(credit);
            income += credit;
            users[index]->setEntryTime();
            qInfo() << "you can enter the parking!" << Qt::endl << users[index]->getEntryTime() << Qt::endl;
            report[users[index]->current_ID + "  entry"] = users[index]->getEntryTime();
            normal[i_normal] = users[index];
            i_normal++;
        }
        else
        {
            qInfo() << "sorry, you cant enter!" << Qt::endl;
        }
    }

}
//*********************************************************************************************
void ParkingNormal::new_user()
{
    if(users.size() == number)
    {
        qInfo() << "sorry, the number of users reached the limit!" << Qt::endl;
        return;
    }
    else
    {
        std::string name, family, car, id;
        char answer;
        double credit;
        qInfo() << "What's your name?" << Qt::endl;
        std::cin >> name;
        qInfo() << "What's your last  name?" << Qt::endl;
        std::cin >> family;
        qInfo() << "what's your car's name?" << Qt::endl;
        std::cin >> car;
        qInfo() << "What's your plate number?" << Qt::endl;
        std::cin >> id;
        qInfo() << "Please, pay at least $100." << Qt::endl;
        std::cin >> credit;
        NormalUser * user = new NormalUser(name, family, car, id, credit);
        user->registerParking();
        qInfo() << "you can register another car too, do you want(Y/N)? ";
        std::cin >> answer;
        if(answer == 'Y')
        {
            qInfo() <<"Please enter your second car's details: " << Qt::endl << "Whats your car's name? " << Qt::endl;
            std::cin >> car;
            user->setCar_2Name(car);
            qInfo() << "Whats your plate number? " << Qt::endl;
            std::cin >> car;
            user->setCar_2ID(car);
            qInfo() <<"done" << Qt::endl;
        }
        user->current_ID = id;
        user->setEntryTime();
        users.push_back(user);
        qInfo() << "you can enter the parking!" << Qt::endl << user->getEntryTime() << Qt::endl;
        report[user->getCarID() + "  entry"] = user->getEntryTime();
        normal[i_normal] = user;
        i_normal++;
        income += credit;
    }

}
//*********************************************************************************************
void ParkingNormal::exit(int i)
{
    double m_cost;
    m_cost = normal[i]->calculateCost(cost);
    normal[i]->useCredit(m_cost);
    normal[i]->setExitTime();
    qInfo() << "your credit:  " << normal[i]->getMonthlyCredit() << Qt::endl;
    qInfo() << "nice day!   " << normal[i]->getExitTime() << Qt::endl;
    report[normal[i]->current_ID + "  exit"] = normal[i]->getExitTime();
    remove(*normal, i);
}
//*********************************************************************************************
void ParkingNormal::remove(NormalUser* normal, int index)
{
    for (int i = index+1; i < i_normal; i++)
        normal[i-1] = normal[i];
    i_normal--;
}
//*********************************************************************************************
void ParkingNormal::getUsers() const
{
    if(users.empty())
    {
        qInfo() << "no normal users have registered yet!" << Qt::endl;
        return;
    }
    qInfo() << "the list of normal users: " << Qt::endl;
    for (int i = 0; i < users.size(); i++)
    {
        users[i]->displayInfo();
    }
}
//*********************************************************************************************
void ParkingNormal::getCurrentUsers() const
{
    if(i_normal == 0)
    {
        qInfo() << "now there is no normal user in the parking!" << Qt::endl;
        return;
    }
    qInfo() << "normal users:" << Qt::endl;
    for (int i = 0; i < i_normal; i++)
    {
        qInfo() << i +1 << "_ " << normal[i]->current_ID << "      " << normal[i]->getEntryTime() << Qt::endl;
    }
}
//*********************************************************************************************
void ParkingNormal::change()
{
    int num, i;
    string id, car;
    qInfo() << "Please enter your plate number: ";
    std::cin >> id;
    for(i = 0; i < users.size(); i++)
    {
        if(users[i]->getCarID() == id || users[i]->getCar_2ID() == id)
            break;
    }
    while(true)
    {
        qInfo() << "choose one of them: " << Qt::endl;
        qInfo() << "1_ add car" << Qt::endl <<"2_ remove car" << Qt::endl << "3_ increase credit" << Qt::endl << "4_ quit" <<Qt::endl;
        std::cin >> num;
        if(num == 1)
        {
            if(users[i]->getCar_2ID().empty())
            {
                qInfo() <<"Please enter your second car's details: " << Qt::endl << "Whats your car's name? " << Qt::endl;
                std::cin >> car;
                users[i]->setCar_2Name(car);
                qInfo() << "Whats your plate number? " << Qt::endl;
                std::cin >> id;
                users[i]->setCar_2ID(id);
                qInfo() <<"done" << Qt::endl;
            }
            else
                qInfo() <<"sorry, you registered second car before!" << Qt::endl;
        }
        else if(num == 2)
        {
            qInfo() << "you can rermove your second car!" << Qt::endl;
            if(users[i]->getCar_2ID().empty())
                qInfo() << "sorry, you have just one car!" << Qt::endl;
            else
            {
                users[i]->setCar_2Name("");
                users[i]->setCar_2ID("");
                qInfo() << "done!" << Qt::endl;
            }
        }
        else if(num == 3)
        {
            double credit;
            qInfo() << "how many do you want increase: ";
                std::cin >> credit;
            users[i]->setMonthlyCredit(credit);
            qInfo() << "done!" << Qt::endl;
        }
        else
            return;
    }

}
//*********************************************************************************************
int ParkingNormal::search_current(string id)
{
    for (int i = 0; i < i_normal; i++)
    {
        if(normal[i]->getCarID() == id || normal[i]->getCar_2ID() == id)
            return i;
    }
    return -1;

}
