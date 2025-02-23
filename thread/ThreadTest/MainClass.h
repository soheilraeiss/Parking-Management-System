#ifndef MAINCLASS_H
#define MAINCLASS_H


#include <QMutex>
#include <QObject>

class MainClass : public QObject
{
    Q_OBJECT

public:
    MainClass();
    ~MainClass();

    QVector<qint64> getTempVector();
    void setTempVector(const QVector<qint64> &newTempVector);


private:
    QMutex m_mutex;
    QVector<qint64> m_tempVector;

public slots:
    void slt_variableChanged(qint64 var);


signals:

};

#endif // MAINCLASS_H
