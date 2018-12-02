/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/TimerFactory.h>


namespace cute_adapter_production
{


class TimerFactory :
    public cute_adapter::TimerFactory
{
public:
  void singleShot(int msec, const QObject *receiver, const char *member) override;
  cute_adapter::Timer *timer() override;

};


}
