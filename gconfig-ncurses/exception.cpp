// SPDX-License-Identifier: GPL-3.0-or-later

#include "exception.h"

Exception::Exception()
{}

Exception::Exception(const Throwable &other) : Throwable(other)
{}

Exception::Exception(const std::string &message, Throwable *cause/* = nullptr*/)
    : Throwable(message, cause)
{}

Exception::~Exception()
{}
