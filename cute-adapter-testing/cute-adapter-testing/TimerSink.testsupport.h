/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <QObject>

namespace cute_adapter_testing
{

class SimulatedTimerFactory;


class TimerSink : public QObject
{
  Q_OBJECT
public:
  explicit TimerSink(const SimulatedTimerFactory &factory, QObject *parent = 0);

  quint64 timeout_time() const;

public slots:
  void timeout();

private:
  const SimulatedTimerFactory &_factory;
  quint64 _time{};

};

}
