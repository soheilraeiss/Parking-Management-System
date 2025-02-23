cmake_minimum_required(VERSION 3.16)

project(ParkingManagement VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appParkingManagement
    main.cpp
)

qt_add_qml_module(appParkingManagement
    URI ParkingManagement
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES User.h User.cpp
    SOURCES ParkingManager.h ParkingManager.cpp
    QML_FILES CustomButton.qml
    QML_FILES CustomInput.qml
    QML_FILES ManagerSetupPage.qml
    QML_FILES LoginPage.qml
    QML_FILES RegisterPage.qml
    QML_FILES DailyParkingPage.qml
    QML_FILES UserProfilePage.qml
    QML_FILES NormalParkingPage.qml
    QML_FILES VIPParkingPage.qml

)

# Qt for
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appParkingManagement PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appParkingManagement
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNRSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appParkingManagement
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appParkingManagement
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
