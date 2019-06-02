// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <stdio.h>

#include "file-io.h"

file_size_t get_file_size(const char *filename)
{
    // FILE *fp = fopen(filename, "r");
    // if (!fp)
    //     return -1;
    // fseek(fp, 0L, SEEK_END);
    // int size = ftell(fp);
    // fclose(fp);
    // return size;

    struct stat statbuf;
    stat(filename, &statbuf);
    return statbuf.st_size;
}

file_size_t read_file(const char *filename, void *buf)
{
    if (!buf)
        return -1;
    FILE *fp = fopen(filename, "r");
    file_size_t fs = get_file_size(filename);
    file_size_t rs = fread(buf, 1, fs, fp);
    return rs;
}
