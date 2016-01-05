#include "mainactoins.h"

#include <qdebug.h>

MainActoins::MainActoins(QObject *parent) : QObject(parent)
{
    generator1 = new GenerateDetals(15);
    generator2 = new GenerateDetals(6);
    generator3 = new GenerateDetals(10);

    m_generators << generator1;
    m_generators << generator2;
    m_generators << generator3;

    queue = new CountDetals();

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
    GenerateDetals* tempGen;
    QChar tempDetalType = 'A';

    canConnect = true;
    while(canConnect)
    {
            for(int countGen = 0; countGen < m_generators.size(); countGen++) {
                tempGen = m_generators.at(countGen);
                tempDetalType = 'A' + countGen;
                if(tempGen->isTime()) {
                    queue->add(generator1->GetRequest(tempDetalType));
                qDebug() << "mother of god type" << tempDetalType;
                }
            }


//        if (generator1->isTime())
//            queue->add(generator1->GetRequest('A'));
//        if (generator2->isTime())
//            queue->add(generator2->GetRequest('B'));
//        //    qDebug() << "front" << queue->isAvaliable();
//        if (generator3->isTime())
//            queue->add(generator3->GetRequest('C'));
        //  qDebug() << "last A" << isAvaliable('A',1) << "B" << isAvaliable('B', 2); // проверка, есть ли деталь

        //
        // тут начинается веселье. надо проверять на доступность соединений, плюсовать время работы, сколько заявка в деле
        // расчет рабочих. еще не ясно, как это все реализовать

        // queue->

        for(int i = 1; i < 7;i++) {
            stage(i);
        }

        emit updateStats();
        QEventLoop loop;
        QTimer::singleShot(1000,&loop,SLOT(quit()));
        loop.exec();
    }
}




bool MainActoins::isAvaliable(QChar detal, int count)
{
    Request rec;
    rec.type = detal;
    int num = 0;

    for( int pos = 0 ; pos < queue->getSize(); ++pos) {
        if (queue->at(pos)->type == rec.type) {
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
        if(stage1->isEnded()) {
            queue->add(stage1->GetRequest('D'));
            stage1->setEnd(false);
        }
        if(stage1->isFree()) {
            if(isAvaliable('A',1) && isAvaliable('B', 2)) {
                stage1->setFree(false);
                stage1->connecting("ABB");
            }
        }
        break;
    case 2:
        if(stage2->isEnded()) {
            queue->add(stage2->GetRequest('E'));
            stage2->setEnd(false);
        }
        if(stage2->isFree()) {
            if(isAvaliable('A') && isAvaliable('B') && isAvaliable('C')) {
                stage2->setFree(false);
                stage2->connecting("ABC");
            }
        }
        break;
    case 3:
        if(stage3->isEnded()) {
            queue->add(stage3->GetRequest('D'));
            queue->add(stage3->GetRequest('E'));
            stage3->setEnd(false);
        }
        if(stage3->isFree()) {
            if(isAvaliable('D') && isAvaliable('E')) {
                stage3->setFree(false);
                stage3->connecting("DE");
            }
        }
        break;
    case 4:
        if(stage4->isEnded()) {
            queue->add(stage4->GetRequest('F'));
            stage4->setEnd(false);
        }
        if(stage4->isFree()) {
            if(isAvaliable('D') && isAvaliable('B') && stage3->isFree()) {
                stage4->setFree(false);
                stage4->connecting("DB");
            }
        }
        break;
    case 5:
        if(stage5->isEnded()) {
           queue->add(stage5->GetRequest('G'));
           stage5->setEnd(false);
        }
        if(stage5->isFree()) {
            if(isAvaliable('F') && isAvaliable('E')) {
                stage5->setFree(false);
                stage5->connecting("FE");

            }
        }
        break;
    case 6:
        if(stage6->isEnded()) {
            queue->add(stage6->GetRequest('H'));
            qDebug() << "6 is ended";
            stage6->setEnd(false);
        }
        if(stage6->isFree()) {
            if(isAvaliable('G') && isAvaliable('B') && isAvaliable('C',2)) {
                stage6->setFree(false);
                stage6->connecting("GBCC");
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

int MainActoins::slot_getCountDetals(QChar detal)
{
    Request rec;
    rec.type = detal;
    int num = 0;

    for( int pos = 0 ; pos < queue->getSize(); ++pos) {
        if (queue->at(pos)->type == rec.type) {
            num++;
        }
    }
    return num;
}

int MainActoins::slot_getProcessTime(QChar type, int number)
{
    if(type == 'G')
        switch (number) {
        case 1:
            return generator1->getProcessTime();
        case 2:
            return generator2->getProcessTime();
        case 3:
            return generator3->getProcessTime();
        default:
            break;
        }
    if(type == 'Q')
        switch (number) {
        case 1:
            return stage1->getConnectTime();
        case 2:
            return stage2->getConnectTime();
        case 3:
            return stage3->getConnectTime();
        case 4:
            return stage4->getConnectTime();
        case 5:
            return stage5->getConnectTime();
        case 6:
            return stage6->getConnectTime();
        default:
            break;
        }
}

// ++++ переписать, чтобы деталь добавлялась после обработки ++++
// выводить, что "готовится" на каждом из этапов, сколько осталось
// выводить, сколько до генерации, сколько осталось деталей
// сделать ограничение на детали
// остановить работу, если соединения больше невозможны
// плюсовать время на детали
