#include "countdetals.h"
#include <generatedetals.h>

#include <QDebug>

CountDetals::CountDetals(QObject *parent) : QObject(parent)
{

}

void CountDetals::add(Request* req)
{
    queue.append(req);
    qDebug() << "!!!add!!!";
}

bool CountDetals::isAvaliable(char detal, int count)
{
   Request rec;
   rec.type = detal;
   int num = 0;

   for( int pos = 0 ; pos < queue.size(); ++pos) {
       if (queue.at(pos)->type == rec.type) {
           //
        //   qDebug() << "pos " << queue.at(pos) << pos << rec.type;
           num++;
       }
   }

   if(num >= count) {
       qDebug() << "num" << num;
       return true;
   }
return false;
   //qDebug() << "queue" <<queue.indexOf(rec);
 //  return t;
}

void CountDetals::setProcTime()
{
// Request
}



bool CountDetals::stage(char stage)
{
    switch (stage) {
    case 'D':

        break;
    case 'E':

        break;
    case 'F':

        break;
    case 'G':

        break;
    case 'H':

        break;
    default:
        break;
    }
}
