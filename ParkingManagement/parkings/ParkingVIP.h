#ifndef PARKINGVIP_H
#define PARKINGVIP_H

#include <common/Parking.h>

class ParkingVIP : public Parking
{
private:
    QVector <VIPUser*> users;
    VIPUser** vip = new VIPUser*[number];

public:
    ParkingVIP();
    ~ParkingVIP();
    int i_vip = 0;

    void service(int, std::string);
    void new_user();
    void exit(std::string);
    void remove(VIPUser*, int);
    void getUsers() const;
    void getCurrentUsers() const;
    void change();
    int search(std::string, std::string);
};

#endif // PARKINGVIP_H
