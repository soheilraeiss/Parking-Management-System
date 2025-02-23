#include <QCoreApplication>
#include <ParkingManagement.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ParkingManagement parking;

    return a.exec();
}
