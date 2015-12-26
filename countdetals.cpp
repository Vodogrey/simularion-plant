#include "countdetals.h"
#include <generatedetals.h>

#include <QDebug>

CountDetals::CountDetals(QObject *parent) : QObject(parent)
{

}

void CountDetals::add(Request *req)
{
    queue.append(req);
    qDebug() << "!!!add!!!";
    for(int i = 0; i< queue.size();i++) {
        qDebug() << queue.at(i);
    }
}
