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


void operator>>(std::istringstream&, QString&);
void operator>>(std::istringstream&, QDateTime&);
