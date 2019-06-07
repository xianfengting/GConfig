// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <stdio.h>
#include <unistd.h>

#include "defines.h"
#include "file-io.h"

file_size_t get_file_size(const char *filename)
{
    NULL_POINTER_RETURN_VALUE(filename, -1)

    // FILE *fp = fopen(filename, "r");
    // if (!fp)
    //     return -1;
    // fseek(fp, 0L, SEEK_END);
    // int size = ftell(fp);
    // fclose(fp);
    // return size;

    if (!exist_file(filename))
        return -1;

    struct stat statbuf;
    stat(filename, &statbuf);
    return statbuf.st_size;
}

file_size_t read_file(const char *filename, void *buf)
{
    NULL_POINTER_RETURN_VALUE(filename, -1)
    NULL_POINTER_RETURN_VALUE(buf, -1)
    
    if (!exist_file(filename))
        return -1;

    FILE *fp = fopen(filename, "r");
    file_size_t fs = get_file_size(filename);
    file_size_t rs = fread(buf, 1, fs, fp);
    return rs;
}

bool_t exist_file(const char *filename)
{
    NULL_POINTER_RETURN_VALUE(filename, false)
    int result = access(filename, F_OK);
    return !(result == -1);
}
