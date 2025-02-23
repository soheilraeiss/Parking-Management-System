#ifndef VIPUSER_H
#define VIPUSER_H

#include "user.h/User.h"

class VIPUser : public User {
private:
    double monthlyCredit;
    bool isRegistered;

public:
    VIPUser(const string& driver, const string& family, const string& car, const string& id,
            double initialCredit = 0);
    ~VIPUser();
    
    void registerParking();
    double getMonthlyCredit() const;
    time_t calculateEntryTime() override;
    time_t calculateExitTime() override;
};

#endif
