// SPDX-License-Identifier: GPL-3.0-or-later

#include "throwable.h"

using namespace std;

Throwable::Throwable() : Throwable("")
{}

Throwable::Throwable(const Throwable &other) : Object(other)
{
    InitFields(*(other.m_message), other.m_cause);
}

Throwable::Throwable(const string &message, Throwable *cause/* = nullptr*/)
{
    InitFields(message, cause);
}

Throwable::~Throwable()
{
    delete m_message;
}

const_str_t Throwable::GetMessage() const
{
    return m_message->c_str();
}

void Throwable::SetMessage(const string &message)
{
    m_message->clear();
    m_message->append(message);
}

Throwable *Throwable::GetCause() const
{
    return m_cause;
}

void Throwable::SetCause(Throwable *cause)
{
    m_cause = cause;
}

void Throwable::InitFields(const string &message, Throwable *cause)
{
    m_message = new string(message.c_str());
    m_cause = cause;
}
