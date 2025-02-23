#include "parkings/ParkingDaily.h"
#include <QDebug>
#include <iostream>
#include <string>

ParkingDaily::ParkingDaily()
{
    int num;
    qInfo() << "Please enter the number of daily users: ";
    std::cin >> num;
    setNumber(num);
    qInfo() << "Please enter the cost per hour: ";
    std::cin >> num;
    setCost(num);

}
//***********************************************************************
ParkingDaily::~ParkingDaily()
{

}
//*********************************************************************************************

void ParkingDaily::service()
{
    if(i_daily == number)
    {
        qInfo() << "sorry, parking is full" << Qt::endl;
        return;
    }

    std::string car, id;
    qInfo() << "What's your car's name? " << Qt::endl;
    std::cin >> car;
    qInfo() << "What's your car's plate number?" << Qt::endl;
    std::cin >> id;
    DailyUser * user = new DailyUser(car, id);
    user->setEntryTime();
    qInfo() << "you can enter the parking!" << Qt::endl << user->getEntryTime() << Qt::endl;
    report[user->getCarID() + "  entry"] = user->getEntryTime();
    daily[i_daily] = user;
    i_daily++;

}
//*********************************************************************************************
void ParkingDaily::exit(int i)
{
    std::string id = daily[i]->getCarID();
    double m_cost;
    m_cost = daily[i]->calculateCost(cost);
    qInfo() << "please pay $" << m_cost << Qt::endl << "done!" << Qt::endl;
    daily[i]->setExitTime();
    qInfo() << "nice day!   " << daily[i]->getExitTime() << Qt::endl;
    report[daily[i]->getCarID() + "  exit"] = daily[i]->getExitTime();
    //daily[i]->~DailyUser();
    remove(*daily, i);
}
//*********************************************************************************************
void ParkingDaily::remove(DailyUser* daily, int index)
{
    for (int i = index +1; i < i_daily; i++)
        daily[i-1] = daily[i];
    i_daily--;
}
//**********************************************************************************************
void ParkingDaily::getCurrentUsers() const
{
    if(i_daily == 0)
    {
        qInfo() << "now there is no daily user in the parking!" << Qt::endl;
        return;
    }
    qInfo() << "daily users:" << Qt::endl;
    for (int i = 0; i < i_daily; i++)
    {
        qInfo() << i +1 << "_ " << daily[i]->getCarID() << "      " << daily[i]->getEntryTime() << Qt::endl;
    }
}
//**********************************************************************************************
int ParkingDaily::search_current(string id)
{
    for (int i = 0; i < i_daily; i++)
    {
        if(daily[i]->getCarID() == id)
            return i;
    }
    return -1;
}
//**********************************************************************************************
