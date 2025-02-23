#ifndef DAILYUSER_H
#define DAILYUSER_H

#include "user.h/User.h"

class DailyUser : public User {
public:
    DailyUser(const string& car, const string& id);
    ~DailyUser();

    double calculateCost(double) const;
    time_t calculateEntryTime() override;
    time_t calculateExitTime() override;
};

#endif
