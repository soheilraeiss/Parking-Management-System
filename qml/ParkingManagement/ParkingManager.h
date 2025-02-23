//parkingmanager
#ifndef PARKINGMANAGER_H
#define PARKINGMANAGER_H

#include <QObject>
#include <QMap>
#include <QVector>
#include "User.h"

class ParkingManager : public QObject {
    Q_OBJECT

public:
    explicit ParkingManager(QObject *parent = nullptr);

    struct ParkingConfig {
        int capacity;
        double hourlyRate;
    };

    struct ParkingRecord {
        QString plateNumber;
        QDateTime checkInTime;
    };

public slots:
    bool setupParking(int dailyCapacity, double dailyRate,
                      int normalCapacity, double normalRate,
                      int vipCapacity, double vipRate);

    bool registerUser(const QString& firstName, const QString& lastName,
                      const QString& plateNumber, const QString& carModel,
                      User::UserType type, double initialBalance);

    bool loginUser(const QString& plateNumber);

    bool checkInDaily(const QString& plateNumber);
    bool checkOutDaily(const QString& plateNumber);
    bool checkInNormal(const QString& plateNumber);
    bool checkOutNormal(const QString& plateNumber);
    bool checkInVIP(const QString& plateNumber);
    bool checkOutVIP(const QString& plateNumber);

    //bool checkInRegistered(const QString& plateNumber);
    //bool checkOutRegistered(const QString& plateNumber);

    double getUserBalance(const QString& plateNumber);
    bool addUserBalance(const QString& plateNumber, double amount);

signals:
    void balanceUpdated(double newBalance);

private:
    QMap<QString, User> registeredUsers;
    QMap<QString, ParkingRecord> activeParking;
    QMap<User::UserType, ParkingConfig> parkingConfigs;

    double calculateFee(const QDateTime& checkIn, const QDateTime& checkOut, User::UserType type);
    bool isSpaceAvailable(User::UserType type);
    int getOccupiedSpaces(User::UserType type);
};

#endif // PARKINGMANAGER_H
