#ifndef GENERATEDETALS_H
#define GENERATEDETALS_H

#include <QObject>
#include <qvector.h>

#include <qdebug.h>

struct Request {
    int systemTime;
    int procTime;
    char type;
};

class GenerateDetals : public QObject
{
    Q_OBJECT


public:
    GenerateDetals(int time);
    Request* GetRequest(char typeDetal);
    bool isTime();
    void CalcTime();
    int getCentralTime();
    void setCentralTime(int time);
    void setCalcTime(int time);
private:
    int m_waitTime;
    int m_centralTime;

};

#endif // GENERATEDETALS_H
