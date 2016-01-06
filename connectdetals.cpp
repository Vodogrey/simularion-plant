#include "connectdetals.h"

ConnectDetals::ConnectDetals(int time, int dispersion, CountDetals& count)
{
    setCentralTime(time);
    setCalcTime(0);
    setDispersion(dispersion);
    setCount(&count);
    setEnd(false);
    setFree(true);
}

bool ConnectDetals::isFree()
{
    if(stageFree)
        return true;

    isTime();
    return false;
}


int ConnectDetals::getConnectTime()
{
    return m_connectTime;
}

void ConnectDetals::setCount(CountDetals* detal)
{
    countAddress = detal;
}

void ConnectDetals::setFree(bool free)
{
    stageFree = free;
}

void ConnectDetals::isTime()
{
    m_tempProcTime += 1;
    m_tempSystemTime += 1;

    if(--m_connectTime == 0) {
        setEnd(true);

    }
}

void ConnectDetals::setCalcTime(int time)
{
    m_connectTime = time;
}

void ConnectDetals::setDispersion(int dispersion)
{
    m_dispersion = dispersion;
}

int ConnectDetals::getDispersion()
{
    return m_dispersion;
}

void ConnectDetals::setEnd(bool end)
{
    connectEnded = end;
}

bool ConnectDetals::isEnded()
{
    return connectEnded;
}

void ConnectDetals::CalcTime()
{
    if(m_connectTime <= 0) {
        int dispersion = qrand() % (getDispersion() * 2) + 1 - getDispersion();
        m_connectTime = getCentralTime() + dispersion;
    }
}

int ConnectDetals::getCentralTime()
{
    return m_centralTime;
}

void ConnectDetals::setCentralTime(int time)
{
    m_centralTime = time;
}

void ConnectDetals::connecting(QString detals)
{
    m_tempProcTime = 0;
    m_tempSystemTime = 0;
    setEnd(false);

    Request* rec;
    CalcTime();
    for(int i = 0;i<detals.size();i++) {
        rec = countAddress->getRequest(detals.at(i));
        if(rec->systemTime > m_tempSystemTime)
            m_tempSystemTime = rec->systemTime;
        m_tempProcTime = rec->procTime;
    }
}

Request* ConnectDetals::GetRequest(QChar typeDetal)
{
    Request* request = new Request;
    request->procTime=m_tempProcTime;
    request->systemTime=m_tempSystemTime;
    request->type=typeDetal;
    return request;
}
void ConnectDetals::clear()
{
    setEnd(false);
    setFree(true);
    setCalcTime(0);
}
