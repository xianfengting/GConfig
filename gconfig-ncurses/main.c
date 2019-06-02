// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <stdio.h>

#include "code-parser/parser.h"
#include "file-io.h"
#include "util.h"
#include "main.h"

void gconfig_parse(const char *confFilename)
{
    file_size_t fs = get_file_size(confFilename);
    char *fBuf = xmalloc_type(char, fs);
    read_file(confFilename, fBuf);
    xfree(fBuf);
}
