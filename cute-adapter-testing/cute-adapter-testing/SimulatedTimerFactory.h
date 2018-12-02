/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/TimerFactory.h>

#include <list>

namespace cute_adapter
{

class Time;

}

namespace cute_adapter_testing
{

class SimulatedTimer;


class SimulatedTimerFactory :
    public cute_adapter::TimerFactory
{
public:
  cute_adapter::Timer *timer() override;

  void singleShot(int msec, const QObject *receiver, const char *member) override;

  cute_adapter::Time *create_time() const;

  void forward_time_by_ms(quint64 msec);
  void forward_time_to(const QDateTime &time);
  void forward_time_to_ms(quint64 time);

  void start(SimulatedTimer* timer);
  void stop(SimulatedTimer *timer);

  bool is_active(const SimulatedTimer* timer) const;

  quint64 time_msec() const;

private:

  class ActiveTimer
  {
  public:
    SimulatedTimer *timer;
    quint64 timeout;
  };

  std::list<ActiveTimer>::const_iterator find(const SimulatedTimer* timer) const;

  quint64 _time_ms{0};
  std::list<ActiveTimer> _active_timers{};

};


}
