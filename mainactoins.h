#ifndef MAINACTOINS_H
#define MAINACTOINS_H

#include <QObject>
#include <QTimer>
#include <QEventLoop>


#include "generatedetals.h"
#include "countdetals.h"
#include "connectdetals.h"

class MainActoins : public QObject
{
    Q_OBJECT

public:
    explicit MainActoins(QObject *parent = 0);
    bool isAvaliable(char detal, int count = 1);

    void stage(int stageNum);


signals:

public slots:
    void Process();

private:
    bool canConnect;
    GenerateDetals* generator;
    GenerateDetals* generator2;
    GenerateDetals* generator3;

    CountDetals* queue;

    ConnectDetals* stage1;
    ConnectDetals* stage2;
    ConnectDetals* stage3;
    ConnectDetals* stage4;
    ConnectDetals* stage5;
    ConnectDetals* stage6;

};

#endif // MAINACTOINS_H
