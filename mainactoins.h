#ifndef MAINACTOINS_H
#define MAINACTOINS_H

#include <QObject>
#include <QTimer>
#include <QEventLoop>
#include <QVector>


#include "generatedetals.h"
#include "countdetals.h"
#include "connectdetals.h"

class MainActoins : public QObject
{
    Q_OBJECT

public:
    explicit MainActoins(QObject *parent = 0);
    bool isAvaliable(QChar detal, int count = 1);

    void stage(int stageNum);


signals:
    void updateStats();

public slots:
    void Process();
    int slot_getCountDetals(QChar detal);
    int slot_getProcessTime(QChar type, int number);

private:
    bool canConnect;
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

};

#endif // MAINACTOINS_H
