#include <gtest/gtest.h>
#include <QSignalSpy>
#include <cute-adapter-testing/SimulatedTimerFactory.h>
#include "HelloWorld.h"

class HelloWorld_test
    : public testing::Test
{
public:
    cute_adapter_testing::SimulatedTimerFactory factory;
    HelloWorld testee{factory};
    QSignalSpy printSpy{&testee, SIGNAL(print(QString))};
    QSignalSpy finishedSpy{&testee, SIGNAL(finished())};
};

TEST_F(HelloWorld_test, print_hello_when_started)
{

    testee.start();

    ASSERT_EQ(1, printSpy.count());
    ASSERT_EQ("Hello...", printSpy.at(0).at(0));
}

TEST_F(HelloWorld_test, print_world_when_time_elapsed)
{
    testee.start();
    printSpy.clear();

    factory.forward_time_by_ms(2000);

    ASSERT_EQ(1, printSpy.count());
    ASSERT_EQ("world.", printSpy.at(0).at(0));
}

TEST_F(HelloWorld_test, notify_when_finished)
{
    testee.start();

    factory.forward_time_by_ms(2000);

    ASSERT_EQ(1, finishedSpy.count());
}
