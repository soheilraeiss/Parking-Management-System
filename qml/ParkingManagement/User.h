//user.h
#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

class User {
public:
    enum class UserType {
        DAILY,
        NORMAL,
        VIP
    };

    User();
    User(const QString& firstName, const QString& lastName,
         const QString& plateNumber, const QString& carModel,
         UserType type, double balance = 0.0);

    QString getFirstName() const;
    QString getLastName() const;
    QString getPlateNumber() const;
    QString getCarModel() const;
    UserType getUserType() const;
    double getBalance() const;
    void addBalance(double amount);
    void deductBalance(double amount);

private:
    QString firstName;
    QString lastName;
    QString plateNumber;
    QString carModel;
    UserType type;
    double balance;
};

#endif // USER_H
