#include "users.h/NormalUser.h"

NormalUser::NormalUser(const string& driver, const string& family, const string& car, const string& id,
                       double initialCredit = 0)
    : User(car, id), monthlyCredit(initialCredit), isRegistered(false) 
{
    DriverName = driver;
    LastName = family;
}

NormalUser::~NormalUser()
{
    delete this;
}

double NormalUser::getMonthlyCredit() const
{
    return monthlyCredit;
}

void NormalUser::setMonthlyCredit(double credit)
{
    monthlyCredit += credit;
}

void NormalUser::registerParking() {
    isRegistered = true;
    cout << "Please enter a userName:";
    std::cin >> userName;
    cout << "Please enter a password:";
    std::cin >> password;
    isRegistered = true;
    cout << "your registeration is complete." << endl;
}

void NormalUser::useCredit(double amount) {
        monthlyCredit -= amount;
}

time_t NormalUser::calculateEntryTime() {
    return time(nullptr);
}

time_t NormalUser::calculateExitTime() {
    return time(nullptr);
}

double NormalUser::calculateCost(double cost) const {
    return (getParkingDuration()*(cost)) / 60.0;
}
