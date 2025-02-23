#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

#include <iostream>

#include <MainClass.h>

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker();
    ~Worker();

    qint64 getVariable();
    void setVariable(qint64 newVariable);

    void threadStart();
    void threadStop();

private:
    qint64 m_variable = 0;

    bool m_isReadThread = false;
    std::shared_ptr<QThread> m_thread;

    MainClass *m_mainClass;

    void start();

signals:
    void sgl_variableChanged(qint64 var);
};

#endif // WORKER_H
