#include <QCoreApplication>

#include <vector>
#include <QObject>
#include <iostream>

#include <Worker.h>
#include <MainClass.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainClass m_mainClass;
    Worker m_worker;

    QObject::connect(&m_worker, &Worker::sgl_variableChanged, &m_mainClass, &MainClass::slt_variableChanged, Qt::DirectConnection);

    m_worker.threadStart();

    while (true) {
        if (m_mainClass.getTempVector().size() == 10) {
//            m_worker.threadStop();
            m_worker.~Worker();
            break;
        }
    }

    return a.exec();
}
