// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__PARSER_UTIL
#define __HEADER_FILE_PROTECTION__PARSER_UTIL

#include <sys/stat.h>

#include "typedefs.h"

typedef __off_t file_size_t;

/**
 * Get the size of the target file.
 * @filename: The name/path to the file.
 * return: return -1 if filename is NULL, or the target file does not exist; otherwise return the size of the target file.
 */
extern file_size_t get_file_size(const char *filename);

/**
 * Read the target file to the target buffer.
 * @filename: The name/path to the file.
 * @buf: The target buffer. It must be enough (its size must be larger than the size of the file).
 * return: return -1 if one of the arguments is NULL, or the target file does not exist; otherwise return the size that has read.
 */
extern file_size_t read_file(const char *filename, void *buf);

/*
 * Judge whether the target file exists.
 * return: true if the target file exists; false if the target file does not exist, or filename is NULL.
 */
extern bool_t exist_file(const char *filename);

#endif
