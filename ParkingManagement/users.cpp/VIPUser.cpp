#include "users.h/VIPUser.h"

VIPUser::VIPUser(const string& driver, const string& family, const string& car, const string& id,double initialCredit)
    : User(car, id), monthlyCredit(initialCredit), isRegistered(false) 
{
    DriverName = driver;
    LastName = family;
}

VIPUser::~VIPUser()
{
    delete this;
}
void VIPUser::registerParking() {
    cout << "Please enter a userName:";
    std::cin >> userName;
    cout << "Please enter a password:";
    std::cin >> password;
    isRegistered = true;
    cout << "your registeration is complete." << endl;
}


double VIPUser::getMonthlyCredit() const {
    return monthlyCredit;
}

time_t VIPUser::calculateEntryTime() {
    return time(nullptr);
}

time_t VIPUser::calculateExitTime() {
    return time(nullptr);
}

