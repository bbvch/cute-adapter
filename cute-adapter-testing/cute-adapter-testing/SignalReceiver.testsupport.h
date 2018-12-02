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


class SignalReceiver :
    public QObject
{
  Q_OBJECT
public:
  quint32 tick_count{0};

public slots:
  void tick();

};


}
