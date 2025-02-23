QT += core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ParkingManagement.cpp \
        implementation_parkings/ParkingDaily.cpp \
        implementation_parkings/ParkingNormal.cpp \
        implementation_parkings/ParkingVIP.cpp \
        main.cpp \
        parking/Parking.cpp \
        user.cpp/User.cpp \
        users.cpp/DailyUser.cpp \
        users.cpp/NormalUser.cpp \
        users.cpp/VIPUser.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ParkingManagement.h \
    common/Parking.h \
    parkings/ParkingDaily.h \
    parkings/ParkingNormal.h \
    parkings/ParkingVIP.h \
    user.h/User.h \
    users.h/DailyUser.h \
    users.h/NormalUser.h \
    users.h/VIPUser.h


