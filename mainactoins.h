#ifndef MAINACTOINS_H
#define MAINACTOINS_H

#include <QObject>
#include <QTimer>
#include <QEventLoop>
#include <QVector>


#include "generatedetals.h"
#include "countdetals.h"
#include "connectdetals.h"

class MainActions : public QObject
{
    Q_OBJECT

public:
    explicit MainActions(QObject *parent = 0);
    ~MainActions();
    bool isAvaliable(QChar detal, int count = 1);

    void stage(int stageNum);
    bool isCanWork();
    void setStop(bool stop);


signals:
    void updateStats();
    void workEnded();

public slots:
    void Process(int countDetals);
    int slot_getCountDetals(QChar detal);
    QString slot_getProcessTime(QChar type, int number);
    QString slot_getResult();
    void clear();

private:
    GenerateDetals* generator1;
    GenerateDetals* generator2;
    GenerateDetals* generator3;

    CountDetals* queue;

    ConnectDetals* stage1;
    ConnectDetals* stage2;
    ConnectDetals* stage3;
    ConnectDetals* stage4;
    ConnectDetals* stage5;
    ConnectDetals* stage6;


    QVector<GenerateDetals*> m_generators;
    QVector<ConnectDetals*> m_connections;
    QVector<int> m_resultsInSystem;
    QVector<int> m_resultsInConnections;

    bool m_stop;

};

#endif // MAINACTOINS_H
