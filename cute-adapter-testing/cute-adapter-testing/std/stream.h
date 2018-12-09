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
#include <QVariant>


std::ostream& operator<<(std::ostream&, const QString&);
std::ostream& operator<<(std::ostream&, const QDateTime&);
std::ostream& operator<<(std::ostream&, const QVariant&);
