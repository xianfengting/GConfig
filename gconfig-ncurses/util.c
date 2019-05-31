
#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "consts.h"

void *xmalloc(size_t size)
{
    void *mem = malloc(size);
    if (mem)
        return mem;
    fprintf(stderr, "Error: out of memory.\n");
    exit(EXIT_CODE__OUT_OF_MEMORY);
}
