#include "ParkingManager.h"
#include <iostream>

ParkingManager::ParkingManager(QObject *parent) : QObject(parent) {}

bool ParkingManager::setupParking(int dailyCapacity, double dailyRate,
                                  int normalCapacity, double normalRate,
                                  int vipCapacity, double vipRate) {
    parkingConfigs[User::UserType::DAILY] = {dailyCapacity, dailyRate};
    parkingConfigs[User::UserType::NORMAL] = {normalCapacity, normalRate};
    parkingConfigs[User::UserType::VIP] = {vipCapacity, vipRate};
    return true;
}

bool ParkingManager::registerUser(const QString& firstName, const QString& lastName,
                                  const QString& plateNumber, const QString& carModel,
                                  User::UserType type, double initialBalance) {
    if (registeredUsers.contains(plateNumber)) {
        std::cout << "Plate number already registered" << std::endl;
        return false;
    }

    registeredUsers.insert(plateNumber,
                           User(firstName, lastName, plateNumber, carModel, type, initialBalance));
    std::cout << "User registered successfully" << std::endl;
    return true;
}

bool ParkingManager::loginUser(const QString& plateNumber) {
    if (!registeredUsers.contains(plateNumber)) {
        std::cout << "User not found" << std::endl;
        return false;
    }
    std::cout << "Login successful" << std::endl;
    return true;
}

bool ParkingManager::checkInDaily(const QString& plateNumber) {
    if (!isSpaceAvailable(User::UserType::DAILY)) {
        std::cout << "No available space in daily parking" << std::endl;
        return false;
    }

    activeParking[plateNumber] = {plateNumber, QDateTime::currentDateTime()};
    std::cout <<  "Daily check-in successful" << std::endl;
    return true;
}

bool ParkingManager::checkOutDaily(const QString& plateNumber) {
    if (!activeParking.contains(plateNumber)) {
        std::cout << "Vehicle not found in parking" << std::endl;
        return false;
    }

    QDateTime checkOut = QDateTime::currentDateTime();
    double fee = calculateFee(activeParking[plateNumber].checkInTime,
                              checkOut, User::UserType::DAILY);

    activeParking.remove(plateNumber);
    std::cout << "Please pay: $" << fee << std::endl;
    return true;
}

bool ParkingManager::checkInNormal(const QString& plateNumber) {
    if (!isSpaceAvailable(User::UserType::NORMAL)) {
        std::cout << "No available space in daily parking" << std::endl;
        return false;
    }
    else if(!registeredUsers.contains(plateNumber)) {
        std::cout << "sorry, your not a normal user!" << std::endl;
        return false;
    }
    activeParking[plateNumber] = {plateNumber, QDateTime::currentDateTime()};
    std::cout <<  "Normal check-in successful" << std::endl;
    return true;
}

bool ParkingManager::checkOutNormal(const QString& plateNumber) {
    if (!activeParking.contains(plateNumber)) {
        std::cout << "Vehicle not found in parking" << std::endl;
        return false;
    }

    QDateTime checkOut = QDateTime::currentDateTime();
    double fee = calculateFee(activeParking[plateNumber].checkInTime,
                              checkOut, User::UserType::DAILY);

    activeParking.remove(plateNumber);
    std::cout << "Please pay: $" << fee << std::endl;
    return true;
}

bool ParkingManager::checkInVIP(const QString& plateNumber) {
    if (!isSpaceAvailable(User::UserType::VIP)) {
        std::cout << "No available space in daily parking" << std::endl;
        return false;
    }
    else if(!registeredUsers.contains(plateNumber)) {
        std::cout << "sorry, your not a vip user!" << std::endl;
        return false;
    }
    activeParking[plateNumber] = {plateNumber, QDateTime::currentDateTime()};
    std::cout <<  "VIP check-in successful" << std::endl;
    return true;
}

bool ParkingManager::checkOutVIP(const QString& plateNumber) {
    if (!activeParking.contains(plateNumber)) {
        std::cout << "Vehicle not found in parking" << std::endl;
        return false;
    }

    QDateTime checkOut = QDateTime::currentDateTime();
    double fee = calculateFee(activeParking[plateNumber].checkInTime,
                              checkOut, User::UserType::DAILY);

    activeParking.remove(plateNumber);
    std::cout << "done!" << std::endl;
    return true;
}

double ParkingManager::getUserBalance(const QString &plateNumber)
{
    return registeredUsers[plateNumber].getBalance();
}

bool ParkingManager::addUserBalance(const QString &plateNumber, double amount)
{
    if (!registeredUsers.contains(plateNumber)) {
        std::cout << "User not found" << std::endl;
        return false;
    }
    registeredUsers[plateNumber].addBalance(amount);
    std::cout << "added!" << std::endl;
    return true;
}

double ParkingManager::calculateFee(const QDateTime& checkIn,
                                    const QDateTime& checkOut,
                                    User::UserType type) {
    int hours = std::ceil(checkIn.secsTo(checkOut) / 3600.0);
    return hours * parkingConfigs[type].hourlyRate;
}

bool ParkingManager::isSpaceAvailable(User::UserType type) {
    return getOccupiedSpaces(type) < parkingConfigs[type].capacity;
}

int ParkingManager::getOccupiedSpaces(User::UserType type) {
    int count = 0;
    for (const auto& record : activeParking) {
        if (registeredUsers.contains(record.plateNumber)) {
            if (registeredUsers[record.plateNumber].getUserType() == type)
                count++;
        } else if (type == User::UserType::DAILY) {
            count++;
        }
    }
    return count;
}
