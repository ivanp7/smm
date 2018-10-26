#ifndef _LIBSMM_H
#define _LIBSMM_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char* smm_get_root(void);

/****************************************************************/

enum SMM_OBJECT_TYPE
{
    SMM_OBJ_FILE,
    SMM_OBJ_ARGUMENT,
    SMM_OBJ_DIRECTORY,

    SMM_OBJ_PREDICATE,
    SMM_OBJ_SENTENCE
};

void smm_print_abs_path_to_root(void);
void smm_print_path_to_element(enum SMM_OBJECT_TYPE eltype);

#endif //_LIBSMM_H

