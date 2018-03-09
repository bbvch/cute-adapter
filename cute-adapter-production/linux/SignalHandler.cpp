/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "SignalHandler.h"

#include <QSocketNotifier>
#include <QDebug>

#include <sys/signalfd.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


namespace cute_adapter_production
{
namespace linux
{


SignalHandler::SignalHandler(const QSet<int> &handledSignals, QObject *parent) :
  cute_adapter::linux::SignalHandler(parent)
{
  sigset_t mask;

  ::sigemptyset(&mask);
  for (auto sig : handledSignals) {
    if (::sigaddset(&mask, sig) == -1) {
      qFatal("could not configure signal for capturing");
    }
  }

  /* Block signals so that they aren't handled
       according to their default dispositions */
  if (::sigprocmask(SIG_BLOCK, &mask, NULL) == -1) {
    qFatal("could not set sigprocmask");
  }

  fileDescriptor = ::signalfd(-1, &mask, SFD_NONBLOCK);
  if (fileDescriptor == -1) {
    qFatal("could not signalfd");
  }

  auto *socket = new QSocketNotifier(fileDescriptor, QSocketNotifier::Read, this);
  connect(socket, &QSocketNotifier::activated, this, &SignalHandler::handle);
}

SignalHandler::~SignalHandler()
{
  ::close(fileDescriptor);
}

void SignalHandler::handle()
{
  while (true) {
    struct signalfd_siginfo fdsi;
    const auto readSize = sizeof(fdsi);

    const auto res = read(fileDescriptor, &fdsi, readSize);

    switch (res) {
      case readSize:
        received(fdsi.ssi_signo);
        break;

      case -1:
        if (errno != EAGAIN) {
          qDebug() << "signal file descriptor returned error" << errno;
          qFatal("error reading signal file descriptor");
        }
        return;

      default:
        qDebug() << "read unuexpected size from signal file descriptor" << res;
        qFatal("error reading signal file descriptor");
        break;
    }
  }
}


}
}
