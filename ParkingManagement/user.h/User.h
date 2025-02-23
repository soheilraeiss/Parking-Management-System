#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class User {
protected:
    string DriverName;
    string LastName;
    string CarName[2];
    string CarID[2];
    string userName = "";
    string password = "";
    time_t EntryTime;
    time_t ExitTime;

public:
    User(const string& car, const string& id);
    virtual ~User();
    string current_ID;

    virtual time_t calculateEntryTime() = 0;
    virtual time_t calculateExitTime() = 0;

    void setEntryTime();
    void setExitTime();

    string getDriverName() const;
    string getLastName() const;
    string getCarName() const;
    string getCarID() const;
    string getCar_2Name() const;
    string getCar_2ID() const;
    void setCar_2Name(std::string);
    void setCar_2ID(std::string);
    char* getEntryTime() const;
    char* getExitTime() const;

    int getParkingDuration() const;
    virtual void displayInfo() const;
    string getUserName() const;
    void setUserName(const string &newUserName);
    string getPassword() const;
    void setPassword(const string &newPassword);
};

#endif
