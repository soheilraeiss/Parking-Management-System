#ifndef NORMALUSER_H
#define NORMALUSER_H

#include "user.h/User.h"

class NormalUser : public User {
private:
    double monthlyCredit;
    bool isRegistered;

public:
    NormalUser(const string& driver, const string& family, const string& car, const string& id,
               double initialCredit);
    ~NormalUser();
    
    void registerParking();
    void useCredit(double amount);
    void setMonthlyCredit(double);
    double getMonthlyCredit()const;
    double calculateCost(double) const;
    time_t calculateEntryTime() override;
    time_t calculateExitTime() override;
};

#endif
