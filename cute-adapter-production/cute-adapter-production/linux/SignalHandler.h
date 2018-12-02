/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/linux/SignalHandler.h>

#include <QObject>
#include <QSet>

#include <signal.h>


namespace cute_adapter_production
{
namespace linux
{


class SignalHandler :
    public cute_adapter::linux::SignalHandler
{
public:
  explicit SignalHandler(const QSet<int> &handledSignals = {SIGINT}, QObject *parent = nullptr);
  ~SignalHandler();

private slots:
    void handle();

private:
    int fileDescriptor;

};


}
}
