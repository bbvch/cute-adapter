/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "SimulatedTimer.h"

#include "SimulatedTimerFactory.h"

namespace cute_adapter_testing
{


SimulatedTimer::SimulatedTimer(SimulatedTimerFactory &time) :
  _time{time}
{
}

bool SimulatedTimer::isActive() const
{
  return _time.is_active(this);
}

void SimulatedTimer::setInterval(int msec)
{
  Q_ASSERT(msec >= 0);
  _interval_msec = msec;
}

int SimulatedTimer::interval() const
{
  return _interval_msec;
}

void SimulatedTimer::setSingleShot(bool singleShot)
{
  _singleShot = singleShot;
}

bool SimulatedTimer::isSingleShot() const
{
  return _singleShot;
}

void SimulatedTimer::start()
{
  _time.start(this);
}

void SimulatedTimer::stop()
{
  _time.stop(this);
}


}
