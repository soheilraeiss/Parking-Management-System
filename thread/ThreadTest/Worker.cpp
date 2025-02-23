#include "Worker.h"

Worker::Worker()
{
    m_thread = std::make_shared<QThread>();
}

//*****************************************************************************

Worker::~Worker()
{
    m_thread = nullptr;
}


//*************************************************************************************************


qint64 Worker::getVariable()
{
    return m_variable;
}

//*****************************************************************************

void Worker::setVariable(qint64 newVariable)
{
    m_variable = newVariable;
}

//*****************************************************************************

void Worker::threadStart()
{
    this->moveToThread(m_thread.get());
    connect(m_thread.get(), &QThread::started, this, &Worker::start);
    connect(m_thread.get(), &QThread::finished, m_thread.get(), &QObject::deleteLater);
    m_thread->start();
}

//*****************************************************************************

void Worker::threadStop()
{
    m_thread->deleteLater();
    m_thread->wait();
}


//*************************************************************************************************


void Worker::start()
{
    m_isReadThread = true;
    while (m_isReadThread) {

        m_variable++;

        std::cout << "myVar -> " << m_variable << std::endl;

        emit sgl_variableChanged(m_variable);

        m_thread->msleep(1000);
    }
}

//*****************************************************************************

