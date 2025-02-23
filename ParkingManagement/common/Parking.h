#ifndef PARKING_H
#define PARKING_H

#include <QObject>
#include <QVector>
#include <map>
#include <ctime>
#include <QList>
#include <QDebug>

#include <users.h/NormalUser.h>
#include <users.h/DailyUser.h>
#include <users.h/VIPUser.h>

class Parking : public QObject
{
    Q_OBJECT
protected:
    int number = 0;
    double cost;
    static map<string, char*> report;  // general report
    static double income; //income

public:
    Parking();
    ~Parking();

    int getNumber() const;
    void setNumber(int newNumber);
    int getCost() const;
    void setCost(int newCost);
    void setIncome(double);
    double getIncome() const;


    void printGeneralReport();

};

#endif // PARKING_H
