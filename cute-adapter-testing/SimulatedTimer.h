/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Timer.h>

#include <QObject>
#include <list>

namespace cute_adapter_testing
{

class SimulatedTimerFactory;


class SimulatedTimer :
    public cute_adapter::Timer
{
  Q_OBJECT

public:
  explicit SimulatedTimer(SimulatedTimerFactory &time);

  bool isActive() const override;
  void setInterval(int msec) override;
  int interval() const override;
  void setSingleShot(bool singleShot) override;
  bool isSingleShot() const;

public slots:
  void start() override;
  void stop() override;

private:
  SimulatedTimerFactory &_time;
  bool _singleShot{false};
  quint64 _interval_msec{0};
};


}
