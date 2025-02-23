#ifndef PARKINGMANAGEMENT_H
#define PARKINGMANAGEMENT_H

#include <QObject>
#include <parkings/ParkingVIP.h>
#include <parkings/ParkingNormal.h>
#include <parkings/ParkingDaily.h>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QStringList>
#include <string>
using std::string;

class ParkingManagement : public QObject
{
    Q_OBJECT
private:
    int n_floor;
    int n_number;
    QString homePath; // Add this line
    void saveToCSV(const QString& filename, const QStringList& data);

public:
    ParkingManagement();
    ~ParkingManagement();

    int getN_floor() const;
    void setN_floor(int newN_floor);
    int getN_number() const;
    void setN_number(int newN_number);
    void get_information();
    void start(ParkingNormal*, ParkingVIP*, ParkingDaily*);
    void manager(ParkingNormal*, ParkingVIP*, ParkingDaily*);
    void user_entry(ParkingNormal*, ParkingVIP*, ParkingDaily*);
    void user_exit(ParkingNormal*, ParkingVIP*, ParkingDaily*);
    void printUsers(ParkingNormal*, ParkingVIP*);
    void printCurrentReport(ParkingNormal*, ParkingVIP*, ParkingDaily*);
    void changes(ParkingNormal*, ParkingVIP*);
    QString filePath;
    void saveToCSV();

};

#endif // PARKINGMANAGEMENT_H
