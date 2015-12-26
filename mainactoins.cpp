#include "mainactoins.h"

#include <qdebug.h>

MainActoins::MainActoins(QObject *parent) : QObject(parent)
{
 generator = new GenerateDetals(10);
 generator2 = new GenerateDetals(15);
 generator3 = new GenerateDetals(20);

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
        if (generator3->isTime())
            queue->add(generator3->GetRequest('C'));
           // qDebug() << generator->GetRequest('A') << "g2" << generator2->GetRequest('B');


    }
}
