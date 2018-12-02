/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <QObject>

#undef linux


namespace cute_adapter
{
namespace linux
{


class SignalHandler :
    public QObject
{
  Q_OBJECT
public:
  explicit SignalHandler(QObject *parent = nullptr);

signals:
    void received(int);

};


}
}
