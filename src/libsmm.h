#ifndef _LIBSMM_H
#define _LIBSMM_H

#include <string.h>

char* smm_get_root(void);

int smm_init_root(void);

/****************************************************************/

enum SMM_OBJECT_TYPE
{
    SMM_OBJ_FILE,
    SMM_OBJ_ARGUMENT,
    SMM_OBJ_DIRECTORY,

    SMM_OBJ_PREDICATE,
    SMM_OBJ_SENTENCE
};

#endif //_LIBSMM_H

