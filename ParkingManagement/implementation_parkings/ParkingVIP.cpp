#include "parkings/ParkingVIP.h"
#include <QDebug>
#include <iostream>

ParkingVIP::ParkingVIP()
{
    int num;
    qInfo() << "Please enter the number of VIP users: ";
    std::cin >> num;
    setNumber(num);
    qInfo() << "Please enter the cost per month: ";
    std::cin >> num;
    setCost(num);

}
//***********************************************************************
ParkingVIP::~ParkingVIP()
{
    /*for(int i = 0; i < users.size(); i++)
    {
        users[i]->~VIPUser();
    }*/

}
//*********************************************************************************************
void ParkingVIP::service(int index, string id)
{
    if(i_vip == number)
    {
        qInfo() << "sorry, parking for VIP users is full!" << Qt::endl;
        return;
    }
    if(!users[index]->getCarID().empty() && !users[index]->getCar_2ID().empty())
    {
        if(users[index]->getCarID() == id)
        {
            string id_2 = users[index]->getCar_2ID();
            for (int i = 0; i < i_vip; i++)
            {
                if(vip[i]->current_ID == id_2)
                {
                    qInfo() << "sorry, your another car is in and you can't enter!" <<Qt::endl;
                    return;
                }
            }
        }
        else
        {
            string id_2 = users[index]->getCarID();
            for (int i = 0; i < i_vip; i++)
            {
                if(vip[i]->current_ID == id_2)
                {
                    qInfo() << "sorry, your another car is in and you can't enter!" <<Qt::endl;
                    return;
                }
            }
        }
    }
    users[index]->current_ID = id;
    users[index]->setEntryTime();
    qInfo() << "you can enter the parking!" << Qt::endl << users[index]->getEntryTime() << Qt::endl;
    report[users[index]->current_ID + "  entry"] = users[index]->getEntryTime();
    vip[i_vip] = users[index];
    i_vip++;

}
//*********************************************************************************************
void ParkingVIP::new_user()
{
    if(users.size() == number)
    {
        qInfo() << "sorry, the number of users reached the limit!" << Qt::endl;
        return;
    }
    else
    {
        std::string name, family, car, id;
        double credit;
        int n_month;
        char answer;
        qInfo() << "What's your name?" << Qt::endl;
        std::cin >> name;
        qInfo() << "What's your last  name?" << Qt::endl;
        std::cin >> family;
        qInfo() << "what's your car's name?" << Qt::endl;
        std::cin >> car;
        qInfo() << "What's your plate number?" << Qt::endl;
        std::cin >> id;
        qInfo() << "How many month do you want credit?" << Qt::endl << "one month" << Qt::endl << "two month" << Qt::endl << "three month" << Qt::endl;
        cin >> n_month;
        qInfo() << "Please, pay $" << n_month*(getCost()) << Qt::endl;
        cin >> credit;
        VIPUser * user = new VIPUser(name, family, car, id, credit);
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
        vip[i_vip] = user;
        i_vip++;
        income += credit;
    }
}
//*********************************************************************************************
void ParkingVIP::exit(string id)
{
    for (int i = 0; i < i_vip; i++)
    {
        if(vip[i]->current_ID == id)
        {
            vip[i]->setExitTime();
            qInfo() << "nice day!   " << vip[i]->getExitTime() << Qt::endl;
            report[vip[i]->current_ID + "  exit"] = vip[i]->getExitTime();
            remove(*vip, i);
            break;
        }
    }
    return;
}
//*********************************************************************************************
void ParkingVIP::remove(VIPUser* vip, int index)
{
    for (int i = index+1; i < i_vip; i++)
        vip[i-1] = vip[i];
    i_vip--;
}
//*********************************************************************************************
void ParkingVIP::getUsers() const
{
    if(users.empty())
    {
        qInfo() << "no VIP users have registered yet!" << Qt::endl;
        return;
    }
    qInfo() << "the list of vip users: " << Qt::endl;
    for (int i = 0; i < users.size(); i++)
    {
        users[i]->displayInfo();
    }
}
//*********************************************************************************************
void ParkingVIP::getCurrentUsers() const
{
    if(i_vip == 0)
    {
        qInfo() << "now there is no vip user in the parking!" << Qt::endl;
        return;
    }
    qInfo() << "vip users:" << Qt::endl;
    for (int i = 0; i < i_vip; i++)
    {
        qInfo() << i +1 << "_ " << vip[i]->current_ID << "      " << vip[i]->getEntryTime() << Qt::endl;
    }
}
//*********************************************************************************************
void ParkingVIP::change()
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
        qInfo() << "1_ add car" << Qt::endl <<"2_ remove car" << Qt::endl << "3_ quit" <<Qt::endl;
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
        else
            return;
    }
}
//*********************************************************************************************
int ParkingVIP::search(string name, string pass )
{
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i]->getUserName() == name && users[i]->getPassword() == pass)
            return i;
    }
    return -1;
}
