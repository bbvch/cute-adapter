/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "Timer.h"

namespace cute_adapter_production
{


Timer::Timer()
{
  connect(&_timer, SIGNAL(timeout()), this, SIGNAL(timeout()));
}

bool Timer::isActive() const
{
  return _timer.isActive();
}

void Timer::setInterval(int msec)
{
  _timer.setInterval(msec);
}

int Timer::interval() const
{
  return _timer.interval();
}

void Timer::setSingleShot(bool singleShot)
{
  _timer.setSingleShot(singleShot);
}

void Timer::start()
{
  _timer.start();
}

void Timer::stop()
{
  _timer.stop();
}


}
