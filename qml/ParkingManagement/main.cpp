#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ParkingManager.h>
#include <QtQml>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ParkingManager parkingManager;
    engine.rootContext()->setContextProperty(
        "parkingManager", &parkingManager);

    const QUrl url(u"qrc:/ParkingManagement/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
