#include "mainactoins.h"

#include <qdebug.h>

MainActoins::MainActoins(QObject *parent) : QObject(parent)
{
 generator = new GenerateDetals(15);
 generator2 = new GenerateDetals(6);
 generator3 = new GenerateDetals(10);

 queue = new CountDetals();
}

//MainActoins::~MainActons(QObject *parent)
//{
//    delete generator;
//    delete generator2;
//    delete generator3;
//}

void MainActoins::Process()
{
   // while(canConnect)
    {
        qDebug() << "process";
        if (generator->isTime())
            queue->add(generator->GetRequest('A'));
        if (generator2->isTime())
            queue->add(generator2->GetRequest('B'));
    //    qDebug() << "front" << queue->isAvaliable();
        if (generator3->isTime())
            queue->add(generator3->GetRequest('C'));
        qDebug() << "last" << queue->isAvaliable('A',1) << queue->isAvaliable('B', 2);

        //
        // тут начинается веселье. надо проверять на доступность соединений, плюсовать время работы, сколько заявка в деле
        // расчет рабочих. еще не ясно, как это все реализовать

       // queue->

    }
}

bool MainActoins::stage(char stage)
{

}
