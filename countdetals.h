#ifndef COUNTDETALS_H
#define COUNTDETALS_H

#include <QObject>

#include "generatedetals.h"

class CountDetals : public QObject
{
    Q_OBJECT
public:
    explicit CountDetals(QObject *parent = 0);
    void add(Request* req);
    bool isAvaliable(char detal, int count);
    void setProcTime();

signals:

public slots:

private:
  QList <Request*> queue; // искать от начала вхождение элемента
};

#endif // COUNTDETALS_H
