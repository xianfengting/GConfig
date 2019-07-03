// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __HEADER_FILE_PROTECTION__EXCEPTION_H
#define __HEADER_FILE_PROTECTION__EXCEPTION_H

#include "throwable.h"

class Exception : public Throwable
{
public:
    Exception();
    Exception(const Throwable &other);
    Exception(const std::string &message, Throwable *cause = nullptr);
    virtual ~Exception();
};

#endif
