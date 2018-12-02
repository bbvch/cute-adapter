/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "TimerFactory.h"

#include <cute-adapter-production/Timer.h>

#include <QTimer>

namespace cute_adapter_production
{


void TimerFactory::singleShot(int msec, const QObject *receiver, const char *member)
{
  QTimer::singleShot(msec, receiver, member);
}

cute_adapter::Timer *TimerFactory::timer()
{
  return new cute_adapter_production::Timer();
}


}
