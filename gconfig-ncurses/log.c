// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <stdio.h>

#include "log.h"

void log_d(const char *tag, const char *content)
{
    log(tag, content, LOG_TYPE__DEBUG);
}

void log_i(const char *tag, const char *content)
{
    log(tag, content, LOG_TYPE__INFO);
}

void log_w(const char *tag, const char *content)
{
    log(tag, content, LOG_TYPE__WARNING);
}

void log_e(const char *tag, const char *content)
{
    log(tag, content, LOG_TYPE__ERROR);
}

void log(const char *tag, const char *content, enum log_type type)
{
    const char *headStr = "";
    switch (type)
    {
    case LOG_TYPE__DEBUG:
        headStr = "DEBUG";
        break;
    case LOG_TYPE__INFO:
        headStr = "INFO";
        break;
    case LOG_TYPE__WARNING:
        headStr = "WARNING";
        break;
    case LOG_TYPE__ERROR:
        headStr = "ERROR";
        break;
    }
    struct _IO_FILE *ioStream;
    if (type == LOG_TYPE__ERROR)
        ioStream = stderr;
    else
        ioStream = stdin;
    fprintf(ioStream, "[%s] [%s] %s\n", headStr, tag, content);
}
