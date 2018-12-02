/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "SimulatedTime.h"
#include "SimulatedTimer.h"
#include "SimulatedTimerFactory.h"

#include "SignalReceiver.testsupport.h"
#include "Time.dummy.h"
#include "TimerSink.testsupport.h"

#include <gtest/gtest.h>
#include <QtTest/QSignalSpy>

#include <limits>


namespace
{

class SimulatedTimer_Single_Test :
    public testing::Test
{
public:

  void SetUp() override
  {
    testee.setSingleShot(true);
    ASSERT_TRUE(timout.isValid());
  }

  cute_adapter_testing::SimulatedTimerFactory factory{};
  cute_adapter_testing::SimulatedTimer testee{factory};
  QSignalSpy timout{&testee, SIGNAL(timeout())};
};

TEST_F(SimulatedTimer_Single_Test, does_not_fire_when_not_active)
{
  testee.setInterval(10);

  factory.forward_time_by_ms(20);

  ASSERT_EQ(0, timout.count());
}

TEST_F(SimulatedTimer_Single_Test, does_fire_when_next_time_is_timout_time)
{
  testee.setInterval(10);
  testee.start();

  factory.forward_time_by_ms(10);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimer_Single_Test, does_fire_once_when_active)
{
  testee.setInterval(10);
  testee.start();

  factory.forward_time_to_ms(100);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimer_Single_Test, does_fire_when_next_time_is_timout_time_and_timer_is_started_late)
{
  factory.forward_time_to_ms(15);
  testee.setInterval(10);
  testee.start();

  factory.forward_time_to_ms(25);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimer_Single_Test, start_when_started_does_restart_the_timer)
{
  testee.setInterval(10);
  testee.start();
  factory.forward_time_to_ms(5);

  testee.start();

  factory.forward_time_to_ms(10);
  ASSERT_EQ(0, timout.count());
}

TEST_F(SimulatedTimer_Single_Test, can_stop_when_not_running)
{

  ASSERT_NO_THROW(testee.stop());

}


class SimulatedTimer_Interval_Test :
    public testing::Test
{
public:

  void SetUp() override
  {
    testee.setSingleShot(false);
    ASSERT_TRUE(timout.isValid());
  }

  cute_adapter_testing::SimulatedTimerFactory factory{};
  cute_adapter_testing::SimulatedTimer testee{factory};
  QSignalSpy timout{&testee, SIGNAL(timeout())};
};

TEST_F(SimulatedTimer_Interval_Test, does_not_fire_when_not_active)
{
  testee.setInterval(10);

  factory.forward_time_to_ms(100);

  ASSERT_EQ(0, timout.count());
}

TEST_F(SimulatedTimer_Interval_Test, does_fire_when_next_time_is_timout_time)
{
  testee.setInterval(10);
  testee.start();

  factory.forward_time_to_ms(10);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimer_Interval_Test, does_not_fire_when_not_in_interval)
{
  factory.forward_time_to_ms(11);
  testee.setInterval(10);
  testee.start();

  factory.forward_time_to_ms(15);

  ASSERT_EQ(0, timout.count());
}

TEST_F(SimulatedTimer_Interval_Test, does_not_fire_when_last_time_is_timout_time)
{
  testee.setInterval(10);
  factory.forward_time_to_ms(10);
  testee.start();

  factory.forward_time_to_ms(19);

  ASSERT_EQ(0, timout.count());
}

TEST_F(SimulatedTimer_Interval_Test, fires_multiple_times_in_long_period)
{
  testee.setInterval(10);
  testee.start();

  factory.forward_time_to_ms(70);

  ASSERT_EQ(7, timout.count());
}




class SimulatedTimerFactory_Test :
    public testing::Test
{
public:

  void SetUp() override
  {
    ASSERT_TRUE(timout.isValid());
  }

  void TearDown() override
  {
    delete timer;
    delete time;
  }

  cute_adapter_testing::SimulatedTimerFactory testee{};
  cute_adapter::Timer *timer{testee.timer()};
  QSignalSpy timout{timer, SIGNAL(timeout())};
  cute_adapter::Time *time{testee.create_time()};
};


TEST_F(SimulatedTimerFactory_Test, does_not_fire_when_not_started)
{
  timer->setInterval(10);

  testee.forward_time_by_ms(1000);

  ASSERT_EQ(0, timout.count());
}

TEST_F(SimulatedTimerFactory_Test, fires_once_in_single_shot_mode)
{
  timer->setSingleShot(true);
  timer->setInterval(10);
  timer->start();

  testee.forward_time_by_ms(1000);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimerFactory_Test, fires_multiple_times_in_interval_mode)
{
  timer->setSingleShot(false);
  timer->setInterval(100);
  timer->start();

  testee.forward_time_by_ms(1000);

  ASSERT_EQ(10, timout.count());
}

TEST_F(SimulatedTimerFactory_Test, keeps_track_of_time)
{
  timer->setSingleShot(true);
  timer->setInterval(10);
  timer->start();

  testee.forward_time_by_ms(8);
  testee.forward_time_by_ms(1);
  testee.forward_time_by_ms(1);
  testee.forward_time_by_ms(1);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimerFactory_Test, starts_at_the_dawn_of_unix_time)
{
  ASSERT_EQ(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0), Qt::UTC), time->now());
}

TEST_F(SimulatedTimerFactory_Test, forwards_absolute_time)
{

  testee.forward_time_by_ms(1000);

  ASSERT_EQ(QDateTime(QDate(1970, 1, 1), QTime(0, 0, 1), Qt::UTC), time->now());
}

TEST_F(SimulatedTimerFactory_Test, forward_to_a_specific_time)
{
  const QDateTime destination{{1970, 1, 2}, {12, 13, 0}, Qt::UTC};

  testee.forward_time_to(destination);

  ASSERT_EQ(destination, time->now());
}

TEST_F(SimulatedTimerFactory_Test, can_not_go_back_in_time)
{
  const QDateTime destination{{1955, 11, 5}, {1, 20, 0}, Qt::UTC};


  ASSERT_THROW(testee.forward_time_to(destination), std::invalid_argument);
}

TEST_F(SimulatedTimerFactory_Test, can_start_timer_when_time_has_offset)
{
  const QDateTime destination{{2011, 11, 5}, {1, 20, 15}, Qt::UTC};
  testee.forward_time_to(destination);
  timer->setSingleShot(true);
  timer->setInterval(60*60*1000);
  timer->start();

  testee.forward_time_by_ms(60*60*1000);

  ASSERT_EQ(1, timout.count());
}

TEST_F(SimulatedTimerFactory_Test, has_destination_time_when_forwarded)
{
  const auto timer = testee.timer();
  const auto time = testee.create_time();
  timer->setInterval(10);
  timer->start();

  testee.forward_time_to_ms(123);

  ASSERT_EQ(123, time->now().toMSecsSinceEpoch());

  delete time;
  delete timer;
}



TEST(SimulatedTimerFactory_Single_Test, fires_single_shot)
{
  cute_adapter_testing::SimulatedTimerFactory testee{};
  cute_adapter_testing::SignalReceiver receiver;

  testee.singleShot(10, &receiver, SLOT(tick()));

  testee.forward_time_by_ms(1000);

  ASSERT_EQ(1, receiver.tick_count);
}

TEST(SimulatedTimerFactory_Single_Test, is_relative_to_current_time)
{
  cute_adapter_testing::SimulatedTimerFactory testee{};
  cute_adapter_testing::SignalReceiver receiver;

  testee.forward_time_by_ms(9);

  testee.singleShot(10, &receiver, SLOT(tick()));

  testee.forward_time_by_ms(9);
  ASSERT_EQ(0, receiver.tick_count);

  testee.forward_time_by_ms(1);
  ASSERT_EQ(1, receiver.tick_count);
}


class SimulatedTimerFactory_Multiple_Test :
    public testing::Test
{
public:

  SimulatedTimerFactory_Multiple_Test()
  {
    QObject::connect(&timer1, SIGNAL(timeout()), &sink1, SLOT(timeout()));
    QObject::connect(&timer2, SIGNAL(timeout()), &sink2, SLOT(timeout()));
  }

  cute_adapter_testing::SimulatedTimerFactory factory{};
  cute_adapter_testing::SimulatedTimer timer1{factory};
  cute_adapter_testing::SimulatedTimer timer2{factory};

  cute_adapter_testing::TimerSink sink1{factory};
  cute_adapter_testing::TimerSink sink2{factory};

};


TEST_F(SimulatedTimerFactory_Multiple_Test, does_fire_timer_in_correct_order_an_at_correct_time)
{
  timer1.setInterval(10);
  timer1.start();

  timer2.setInterval(7);
  timer2.start();

  factory.forward_time_by_ms(10);

  ASSERT_EQ(10, sink1.timeout_time());
  ASSERT_EQ(7, sink2.timeout_time());
}



}

