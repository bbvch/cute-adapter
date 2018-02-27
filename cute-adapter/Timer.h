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


class Timer :
    public QObject
{
  Q_OBJECT

public:
  virtual ~Timer();

  virtual bool isActive() const = 0;
  virtual void setInterval(int msec) = 0;
  virtual int interval() const = 0;
  virtual void setSingleShot(bool singleShot) = 0;

signals:
  void timeout();

public slots:
  virtual void start() = 0;
  virtual void stop() = 0;

};


}
