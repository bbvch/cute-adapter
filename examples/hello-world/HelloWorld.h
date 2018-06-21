#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QObject>
#include <cute-adapter/TimerFactory.h>

class HelloWorld : public QObject
{
    Q_OBJECT
public:
    explicit HelloWorld(cute_adapter::TimerFactory &factory, QObject *parent = 0);

    void start();

signals:
    void print(QString);
    void finished();

public slots:

private slots:
    void timeout();

private:
    cute_adapter::TimerFactory &factory;
};

#endif // HELLOWORLD_H
