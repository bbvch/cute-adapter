/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "TimerSink.testsupport.h"

#include "SimulatedTimerFactory.h"

namespace cute_adapter_testing
{


TimerSink::TimerSink(const SimulatedTimerFactory &factory, QObject *parent) :
  QObject{parent},
  _factory{factory}
{
}

quint64 TimerSink::timeout_time() const
{
  return _time;
}

void TimerSink::timeout()
{
  _time = _factory.time_msec();
}


}
