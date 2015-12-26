#ifndef CONNECT_H
#define CONNECT_H

#include <QObject>

class Connect : public QObject
{
    Q_OBJECT
public:
    explicit Connect(QObject *parent = 0);
    bool isAvaliable(int stage);
    /*
     * 0A
     * 1B
     * 2C
     * 3D
     * 4E
     * 5F
     * 6G
    */

signals:

public slots:
};

#endif // CONNECT_H
