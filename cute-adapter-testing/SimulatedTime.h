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

private:
  const SimulatedTimerFactory &_factory;
};


}
