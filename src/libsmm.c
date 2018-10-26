#include "libsmm.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define PATH_MAX_STRING_SIZE 256

#define SMM_DIR_MODE 0755

char* smm_get_root(void)
{
    return getenv("SMM_ROOT_DIRECTORY");
}

/* recursive mkdir */
static int mkdir_p(const char *dir, const mode_t mode)
{
    char tmp[PATH_MAX_STRING_SIZE];
    char *p = NULL;
    struct stat sb;
    size_t len;

    /* copy path */
    len = strnlen(dir, PATH_MAX_STRING_SIZE);
    if (len == 0 || len == PATH_MAX_STRING_SIZE)
        return -1;

    memcpy(tmp, dir, len);
    tmp[len] = '\0';

    /* remove trailing slash */
    if (tmp[len - 1] == '/')
        tmp[len - 1] = '\0';

    /* check if path exists and is a directory */
    if (stat(tmp, &sb) == 0)
        if (S_ISDIR (sb.st_mode))
            return 0;

    /* recursive mkdir */
    for (p = tmp + 1; *p; p++)
    {
        if (*p == '/')
        {
            *p = 0;
            /* test path */
            if (stat(tmp, &sb) != 0)
            {
                /* path does not exist - create directory */
                if (mkdir(tmp, mode) < 0)
                    return -1;
            }
            else if (!S_ISDIR(sb.st_mode))
                /* not a directory */
                return -1;

            *p = '/';
        }
    }
    /* test path */
    if (stat(tmp, &sb) != 0)
    {
        /* path does not exist - create directory */
        if (mkdir(tmp, mode) < 0)
            return -1;
    }
    else if (!S_ISDIR(sb.st_mode))
        /* not a directory */
        return -1;

    return 0;
}

int smm_init_root(void)
{
    char *root = smm_get_root();

    if (mkdir_p(root, SMM_DIR_MODE) != 0)
        return 0;

    chdir(root);

    mkdir("data", SMM_DIR_MODE);
    mkdir("predicates", SMM_DIR_MODE);
    mkdir("predicates/by-storage", SMM_DIR_MODE);
    mkdir("predicates/by-uuid", SMM_DIR_MODE);
    mkdir("predicates/by-name", SMM_DIR_MODE);

    return 1;
}

