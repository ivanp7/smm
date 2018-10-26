#include "libsmm.h"

#include <stdio.h>

char* smm_get_root(void)
{
    return getenv("SMM_ROOT_DIRECTORY");
}

