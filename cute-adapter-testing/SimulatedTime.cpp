/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "SimulatedTime.h"

#include "SimulatedTimerFactory.h"


namespace cute_adapter_testing
{


SimulatedTime::SimulatedTime(const SimulatedTimerFactory &factory) :
  _factory{factory}
{
}

QDateTime SimulatedTime::now() const
{
  return QDateTime::fromMSecsSinceEpoch(_factory.time_msec(), Qt::TimeSpec::UTC);
}


}
