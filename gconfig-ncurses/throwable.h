// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __HEADER_FILE_PROTECTION__THROWABLE_H
#define __HEADER_FILE_PROTECTION__THROWABLE_H

#include <string>

#include "typedefs.h"
#include "object.h"

class Throwable : public Object
{
public:
    Throwable();
    Throwable(const Throwable &other);
    Throwable(const std::string &message, Throwable *cause = nullptr);
    virtual ~Throwable();

    const_str_t GetMessage() const;
    void SetMessage(const std::string &message);
    Throwable *GetCause() const;
    void SetCause(Throwable *cause);

private:
    std::string *m_message;
    Throwable *m_cause;
    
    void InitFields(const std::string &message, Throwable *cause);
};

#endif
