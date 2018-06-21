#include "HelloWorld.h"

HelloWorld::HelloWorld(cute_adapter::TimerFactory &factory, QObject *parent)
    : QObject{parent}
    , factory{factory}
{
}

void HelloWorld::start()
{
    print("Hello...");

    factory.singleShot(1000, this, SLOT(timeout()));
}

void HelloWorld::timeout()
{
    print("world.");

    finished();
}
