#ifndef PARKINGNORMAL_H
#define PARKINGNORMAL_H

#include <common/Parking.h>

class ParkingNormal : public Parking
{
private:
    QVector <NormalUser*> users;
    NormalUser** normal = new NormalUser*[number];

public:
    ParkingNormal();
    ~ParkingNormal();
    int i_normal= 0;

    void service(std::string);
    void new_user();
    void exit(int);
    void remove(NormalUser*, int);
    void getUsers() const;
    void getCurrentUsers() const;
    void change();
    int search_current(std::string);
};

#endif // PARKINGNORMAL_H
