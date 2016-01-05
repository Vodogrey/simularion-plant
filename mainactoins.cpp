#include "mainactoins.h"

#include <qdebug.h>

MainActoins::MainActoins(QObject *parent) : QObject(parent)
{
    generator = new GenerateDetals(15);
    generator2 = new GenerateDetals(6);
    generator3 = new GenerateDetals(10);

    queue = new CountDetals();
    qDebug() << "queue" << queue;


    //будем создавать объектом каждый обработчик их будет 6, потому что 6 этапов!!!

    stage1 = new ConnectDetals(15,3, *queue);
    stage2 = new ConnectDetals(18, 3, *queue);
    stage3 = new ConnectDetals(5, 2, *queue);
    stage4 = new ConnectDetals(10, 2, *queue);
    stage5 = new ConnectDetals(15, 4, *queue);
    stage6 = new ConnectDetals(20, 5, *queue);
}

//MainActoins::~MainActons(QObject *parent)
//{
//    delete generator;
//    delete generator2;
//    delete generator3;
//}

void MainActoins::Process()
{
    canConnect = true;
    while(canConnect)
    {
        if (generator->isTime())
            queue->add(generator->GetRequest('A'));
        if (generator2->isTime())
            queue->add(generator2->GetRequest('B'));
        //    qDebug() << "front" << queue->isAvaliable();
        if (generator3->isTime())
            queue->add(generator3->GetRequest('C'));
        //  qDebug() << "last A" << isAvaliable('A',1) << "B" << isAvaliable('B', 2); // проверка, есть ли деталь

        //
        // тут начинается веселье. надо проверять на доступность соединений, плюсовать время работы, сколько заявка в деле
        // расчет рабочих. еще не ясно, как это все реализовать

        // queue->

        for(int i = 1; i < 7;i++) {
            stage(i);
        }

        QEventLoop loop;
        QTimer::singleShot(1000,&loop,SLOT(quit()));
        loop.exec();
    }
}




bool MainActoins::isAvaliable(char detal, int count)
{
    Request rec;
    rec.type = detal;
    int num = 0;

    for( int pos = 0 ; pos < queue->getSize(); ++pos) {
        if (queue->at(pos)->type == rec.type) {
            //
            //   qDebug() << "pos " << queue.at(pos) << pos << rec.type;
            num++;
        }
    }

    if(num >= count) {
        return true;
    }
    return false;
}


void MainActoins::stage(int stageNum)
{
    switch (stageNum) {
    case 1:
        if(stage1->isFree()) {
            qDebug() << "FREE 1";
            if(isAvaliable('A',1) && isAvaliable('B', 2)) {
                stage1->setFree(false);
                stage1->connecting("ABB");
                // queue->add(stage1->GetRequest('D')); это вынесем в соединение
            }
        }
        break;
    case 2:
        if(stage2->isFree()) {
            qDebug() << "FREE 2";
            if(isAvaliable('A') && isAvaliable('B') && isAvaliable('C')) {
                stage2->setFree(false);
                stage2->connecting("ABC");
                queue->add(stage1->GetRequest('E'));
            }
        }
        break;
    case 3:
        if(stage3->isFree()) {
            qDebug() << "FREE 3";
            if(isAvaliable('D') && isAvaliable('E')) {
                stage3->setFree(false);
                stage3->connecting("DE");
                queue->add(stage1->GetRequest('D'));
                queue->add(stage1->GetRequest('E'));
            }
        }
        break;
    case 4:
        if(stage4->isFree()) {
            qDebug() << "FREE 4";
            if(isAvaliable('D') && isAvaliable('B') && stage3->isFree()) {
                stage4->setFree(false);
                stage4->connecting("DB");
                queue->add(stage1->GetRequest('F'));
            }
        }
        break;
    case 5:
        if(stage5->isFree()) {
            qDebug() << "FREE 5";
            if(isAvaliable('F') && isAvaliable('E')) {
                stage5->setFree(false);
                stage5->connecting("FE");
                queue->add(stage1->GetRequest('G'));
            }
        }
        break;
    case 6:
        if(stage6->isFree()) {
            qDebug() << "FREE 6";
            if(isAvaliable('G') && isAvaliable('B') && isAvaliable('C',2)) {
                stage6->setFree(false);
                stage6->connecting("GBCC");
                queue->add(stage1->GetRequest('H'));
                qDebug() << "STOP!!!";
                QEventLoop loop;
                QTimer::singleShot(100000,&loop,SLOT(quit()));
                loop.exec();
            }
        }
        break;
    default:
        break;
    }
}


//Request* MainActoins::getQueue(QChar detal)
//{
//    qDebug() << "get";
//    return queue->getRequest(detal);
//}
