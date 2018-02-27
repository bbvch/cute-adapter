/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Timer.h>

#include <QObject>
#include <QTimer>

namespace cute_adapter_production
{


class Timer :
    public cute_adapter::Timer
{
  Q_OBJECT

public:
  Timer();

  bool isActive() const override;
  void setInterval(int msec) override;
  int interval() const override;
  void setSingleShot(bool singleShot) override;

public slots:
  void start() override;
  void stop() override;

private:
  QTimer _timer;

};


}
