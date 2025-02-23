#ifndef PARKINGDAILY_H
#define PARKINGDAILY_H

#include <common/Parking.h>
#include <QVector>

class ParkingDaily : public Parking
{
private:
    DailyUser** daily = new DailyUser*[number];

public:
    ParkingDaily();
    ~ParkingDaily();
    int i_daily = 0;

    void service();
    void exit(int);
    void remove(DailyUser*, int);
    void getCurrentUsers() const;
    int search_current(std::string);
};

#endif // PARKINGDAILY_H
