/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Time.h>

namespace cute_adapter_testing
{

class SimulatedTimerFactory;


class SimulatedTime :
    public cute_adapter::Time
{
public:
  explicit SimulatedTime(const SimulatedTimerFactory &factory);

  QDateTime now() const override;

  void setTimeSpec(Qt::TimeSpec spec);
  void setOffsetFromUtc(int offsetSeconds);

private:
  const SimulatedTimerFactory &_factory;
  Qt::TimeSpec timeSpec{Qt::TimeSpec::UTC};
  int offsetSeconds{0};

};


}
