/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "SimulatedTimerFactory.h"

#include "SimulatedTimer.h"
#include "SimulatedTime.h"

#include <QTimer>
#include <limits>
#include <algorithm>

namespace cute_adapter_testing
{


cute_adapter::Timer *SimulatedTimerFactory::timer()
{
  SimulatedTimer *timer = new SimulatedTimer(*this);
  return timer;
}

void SimulatedTimerFactory::singleShot(int msec, const QObject *receiver, const char *member)
{
  SimulatedTimer *timer = new SimulatedTimer(*this);
  QObject::connect(timer, SIGNAL(timeout()), receiver, member);
  timer->setSingleShot(true);
  timer->setInterval(msec);
  timer->start();
}

cute_adapter::Time *SimulatedTimerFactory::create_time() const
{
  return new SimulatedTime(*this);
}

void SimulatedTimerFactory::forward_time_by_ms(quint64 msec)
{
  forward_time_to_ms(msec + _time_ms);
}

void SimulatedTimerFactory::forward_time_to(const QDateTime &time)
{
  const auto now = SimulatedTime{*this}.now();
  const qint64 delta = now.msecsTo(time);

  if (delta < 0) {
    throw std::invalid_argument("Sorry, can't go back in time");
  }

  forward_time_by_ms(delta);
}

void SimulatedTimerFactory::forward_time_to_ms(quint64 time)
{
  if (time <= _time_ms) {
    throw std::invalid_argument("Sorry, can't go back in time");
  }

  while (!_active_timers.empty()) {
    const auto next_time = _active_timers.front().timeout;

    Q_ASSERT(next_time >= _time_ms);

    if (next_time > time) {
      break;
    }
    _time_ms = next_time;
    SimulatedTimer *timer = _active_timers.front().timer;
    _active_timers.pop_front();
    timer->timeout();
    if (!timer->isSingleShot()) {
      start(timer);
    }
  }

  _time_ms = time;
}

void SimulatedTimerFactory::start(SimulatedTimer *timer)
{
  stop(timer);

  quint64 firetime = _time_ms + timer->interval();
  _active_timers.push_back(ActiveTimer{timer, firetime});

  _active_timers.sort([](const ActiveTimer& left, const ActiveTimer &right){
    return left.timeout < right.timeout;
  });
}

void SimulatedTimerFactory::stop(SimulatedTimer *timer)
{
  const auto idx = find(timer);

  if (idx != _active_timers.end()) {
    _active_timers.erase(idx);
  }
}

bool SimulatedTimerFactory::is_active(const SimulatedTimer *timer) const
{
  const auto idx = find(timer);
  return idx != _active_timers.end();
}

quint64 SimulatedTimerFactory::time_msec() const
{
  return _time_ms;
}

std::list<SimulatedTimerFactory::ActiveTimer>::const_iterator SimulatedTimerFactory::find(const SimulatedTimer *timer) const
{
  return std::find_if(_active_timers.begin(), _active_timers.end(), [timer](const ActiveTimer& current_timer){
    return current_timer.timer == timer;
  });
}


}
