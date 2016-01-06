#include "countdetals.h"
#include <generatedetals.h>

#include <QDebug>

CountDetals::CountDetals(QObject *parent) : QObject(parent)
{

}

void CountDetals::add(Request* req)
{
    queue.append(req);
    //   qDebug() << "!!!add!!!";
}

Request* CountDetals::at(int pos)
{
    return queue.at(pos);
}

int CountDetals::getSize()
{
    return queue.size();
}

Request* CountDetals::getRequest(QChar detal)
{
    for(int i = 0; i<queue.size(); i++) {
        if(queue.at(i)->type == detal) {
            qDebug() << "detal type" << queue.at(i)->type << "address " << queue.at(i);
            return queue.takeAt(i);
        }
    }
    return queue.at(0);
}

void CountDetals::addTime()
{
    for(int i = 0; i<queue.size(); i++) {
        if(queue.at(i)->type != 'H')
            queue.at(i)->systemTime++;
    }
}

void CountDetals::clear()
{
    queue.clear();
}
