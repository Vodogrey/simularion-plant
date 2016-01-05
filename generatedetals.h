#ifndef GENERATEDETALS_H
#define GENERATEDETALS_H

#include <QObject>
#include <qvector.h>

#include <qdebug.h>


class Request {
public:
    int systemTime;
    int procTime;
    QChar type;
/*
    bool operator ==(const Request &r) {
    if (this->type != r.type) {
        return false;
    }
    return true;
    }*/
};

class GenerateDetals : public QObject
{
    Q_OBJECT


public:
    GenerateDetals(int time);
    Request* GetRequest(QChar typeDetal);
    bool isTime();
    void CalcTime();
    int getCentralTime();
    void setCentralTime(int time);
    void setCalcTime(int time);
    int getProcessTime();
private:
    int m_waitTime;
    int m_centralTime;

};

#endif // GENERATEDETALS_H
