#include "MainClass.h"

MainClass::MainClass()
{

}

//*****************************************************************************


MainClass::~MainClass()
{

}


//*************************************************************************************************


QVector<qint64> MainClass::getTempVector()
{
    return m_tempVector;
}

//*****************************************************************************

void MainClass::setTempVector(const QVector<qint64> &newTempVector)
{
    m_tempVector = newTempVector;
}


//*****************************************************************************


void MainClass::slt_variableChanged(qint64 var)
{
    QMutexLocker l(&m_mutex);
    m_tempVector.push_back(var);
}

//*****************************************************************************
