#include "users.h/DailyUser.h"

DailyUser::DailyUser(const string& car, const string& id)
    : User(car, id) {}
    
DailyUser::~DailyUser()
{
    delete this;
}

double DailyUser::calculateCost(double cost) const {
    return (getParkingDuration()*(cost)) / 60.0;
}

time_t DailyUser::calculateEntryTime() {
    return time(nullptr);
}

time_t DailyUser::calculateExitTime() {
    return time(nullptr);
}
