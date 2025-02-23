#include "User.h"

User::User() : balance(0.0), type(UserType::DAILY) {}

User::User(const QString& firstName, const QString& lastName,
           const QString& plateNumber, const QString& carModel,
           UserType type, double balance)
    : firstName(firstName), lastName(lastName),
    plateNumber(plateNumber), carModel(carModel),
    type(type), balance(balance) {}

QString User::getFirstName() const { return firstName; }
QString User::getLastName() const { return lastName; }
QString User::getPlateNumber() const { return plateNumber; }
QString User::getCarModel() const { return carModel; }
User::UserType User::getUserType() const { return type; }
double User::getBalance() const { return balance; }

void User::addBalance(double amount) {
    balance += amount;
}

void User::deductBalance(double amount) {
    balance -= amount;
}
