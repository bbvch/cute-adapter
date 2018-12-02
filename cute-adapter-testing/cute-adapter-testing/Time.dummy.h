/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Time.h>

namespace infrastructure
{


class TimeDummy :
    public cute_adapter::Time
{
public:
  QDateTime now() const override;

  QDateTime _now{QDateTime::fromMSecsSinceEpoch(0, Qt::TimeSpec::UTC)};
};


}
