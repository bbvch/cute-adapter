/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <QObject>

namespace cute_adapter
{

class Timer;


class TimerFactory
{
public:
  virtual ~TimerFactory();

  virtual void singleShot(int msec, const QObject *receiver, const char *member) = 0;
  virtual Timer *timer() = 0;

};


}
