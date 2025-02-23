#include "common/Parking.h"

Parking::Parking()
{

}
//***********************************************************************
Parking::~Parking()
{

}
//*********************************************************************************************
int Parking::getNumber() const
{
    return number;
}
//***********************************************************************
void Parking::setNumber(int newNumber)
{
    number = newNumber;
}
//*********************************************************************************************
int Parking::getCost() const
{
    return cost;
}
//***********************************************************************
void Parking::setCost(int newCost)
{
    cost = newCost;
}
//*********************************************************************************************
void Parking::setIncome(double cost)
{
    income += cost;
}
//***********************************************************************
double Parking::getIncome() const
{
    return income;
}
//*********************************************************************************************
double Parking::income = 0;

map<string, char*> Parking::report;
//*********************************************************************************************
void Parking::printGeneralReport()
{
    if(report.empty())
    {
        qInfo() << "There is no report, no user has used the parking!" << Qt::endl;
        return;
    }
    qInfo() << "the entry and exit hours:" << Qt::endl;
    for (const auto& pair : report)
    {
        qInfo() << pair.first << "      " << pair.second << Qt::endl;
    }
}
//*********************************************************************************************
