/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Time.h>

namespace cute_adapter_production
{


class Time :
    public cute_adapter::Time
{
public:
  QDateTime now() const override;

};


}
