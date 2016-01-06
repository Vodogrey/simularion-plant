#ifndef CONNECTDETALS_H
#define CONNECTDETALS_H

#include <qstring.h>
#include <qlist.h>
#include <qobject.h>

#include "generatedetals.h"
#include "countdetals.h"

class ConnectDetals
{

public:
    ConnectDetals(int time, int dispersion, CountDetals &count);
    bool isFree();
    void isTime();

    void CalcTime();
    void setCalcTime(int time);
    int getCentralTime();
    void setCentralTime(int time);
    void setDispersion(int dispersion);
    int getDispersion();
    void connecting(QString detals);
    Request* GetRequest(QChar typeDetal);
    bool isEnded();
    void setEnd(bool end);
    int getConnectTime();
    void clear();

    void setFree(bool free);
    void setCount(CountDetals* detal);


private:
    int m_connectTime;
    int m_centralTime;
    int m_dispersion;

    int m_tempSystemTime;
    int m_tempProcTime;

    bool stageFree;
    bool connectEnded;

    CountDetals* countAddress;

    QList<Request*> m_detals;
};

#endif // CONNECTDETALS_H
