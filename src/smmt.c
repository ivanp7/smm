#include <locale.h>

#include "smmt.h"
#include "smmt_args.ggo.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    
    struct gengetopt_args_info ai;
    if (cmdline_parser(argc, argv, &ai) != 0) 
    {
        return 1;
    }

    return 0;
}
