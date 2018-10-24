#include <locale.h>
#include <wchar.h>

#include "smmt.h"
#include "smmt_cmdline.ggo.h"

void print_parsing_error(const char *reason)
{
    if(!strcmp(reason, "unknown"))
    {
        printf("Error: unknown action supplied.\n");
    }
    else if(!strcmp(reason, "too_many"))
    {
        printf("Error: too many arguments supplied.\n");
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    
    if (argc == 1)
    {
        cmdline_parser_print_help();
        return 0;
    }

    struct gengetopt_args_info ai;
    if (cmdline_parser(argc-1, argv+1, &ai) != 0) 
    {
        return 1;
    }

    char *action = argv[1];

    if (!strcmp(action, "help"))
    {
        if (argc > 2)
        {
            print_parsing_error("too_many");
            return 1;
        }

        cmdline_parser_print_help();
    }
    else if (!strcmp(action, "version"))
    {
        if (argc > 2)
        {
            print_parsing_error("too_many");
            return 1;
        }

        cmdline_parser_print_version();
    }
    else
    {
        print_parsing_error("unknown");
        return 1;
    }

    return 0;
}
