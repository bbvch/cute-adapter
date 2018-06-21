#include <QCoreApplication>
#include <iostream>
#include <cute-adapter-production/TimerFactory.h>
#include "HelloWorld.h"

int main(int argc, char *argv[])
{
    QCoreApplication app{argc, argv};
    cute_adapter_production::TimerFactory factory;
    HelloWorld helloWorld{factory};

    QObject::connect(&helloWorld, &HelloWorld::print, [](QString message){
        std::cout << message.toStdString() << std::endl;
    });
    QObject::connect(&helloWorld, &HelloWorld::finished, &app, &QCoreApplication::quit);

    helloWorld.start();

    return app.exec();
}
