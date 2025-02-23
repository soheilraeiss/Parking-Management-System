#include "user.h/User.h"

User::User(const string& car, const string& id)
    : EntryTime(0), ExitTime(0)
{
    CarName[0] = car;
    CarID[0] = id;

}

User::~User() {}

void User::setEntryTime() {
    EntryTime = calculateEntryTime();
}

void User::setExitTime() {
    ExitTime = calculateExitTime();
}

string User::getDriverName() const {
    return DriverName;
}

string User::getCarName() const {
    return CarName[0];
}

string User::getLastName() const {
    return LastName;
}

string User::getCarID() const {
    return CarID[0];
}

string User::getCar_2Name() const
{
    return CarName[1];
}

string User::getCar_2ID() const
{
    return CarID[1];
}

void User::setCar_2Name(string car)
{
    CarName[1] = car;
}

void User::setCar_2ID(string id)
{
    CarID[1] = id;
}

string User::getUserName() const
{
    return userName;
}

void User::setUserName(const string &newUserName)
{
    userName = newUserName;
}

string User::getPassword() const
{
    return password;
}

void User::setPassword(const string &newPassword)
{
    password = newPassword;
}

char* User::getEntryTime() const {
    return ctime(&EntryTime);
}

char* User::getExitTime() const {
    return ctime(&ExitTime);
}

int User::getParkingDuration() const {
    if (ExitTime < EntryTime) return 0;
    return static_cast<int>(difftime(ExitTime, EntryTime) / 60);
}

void User::displayInfo() const {
    cout << "Driver Name: " << DriverName << endl << "Driver lastname: " << LastName << endl;
    cout << "Car Name: " << CarName[0] << endl << "Car ID: " << CarID[0] << endl;
    if(!CarName[1].empty())
    {
        cout << "second Car Name: " << CarName[1] << endl << "second Car ID: " << CarID[1] << endl;
    }
    if (EntryTime > 0) {
        cout << "last entry Time: " << ctime(&EntryTime);
    }
    if (ExitTime > 0) {
        cout << "last exit Time: " << ctime(&ExitTime);
        cout << "Parking Duration: " << getParkingDuration() << " minutes" << endl;
    }
}
