/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <ostream>
#include <QString>
#include <QDateTime>


void PrintTo(const QString&, std::ostream*);
void PrintTo(const QDateTime&, std::ostream*);
