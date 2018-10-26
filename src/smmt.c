#include <locale.h>
#include <sysexits.h>

#include "libsmm.h"
#include "smmt.h"
#include "smmt_cmdline.ggo.h"

static void print_parsing_error(const char *reason)
{
    if (!strcmp(reason, "unknown"))
    {
        printf("Error: unknown action supplied.\n");
    }
    /* else if (!strcmp(reason, "too_many")) */
    /* { */
    /*     printf("Error: too many arguments supplied.\n"); */
    /* } */
}

int act_init(struct gengetopt_args_info *ai);
int act_new(struct gengetopt_args_info *ai);
int act_path(struct gengetopt_args_info *ai);
int act_copy(struct gengetopt_args_info *ai);
int act_move(struct gengetopt_args_info *ai);
int act_delete(struct gengetopt_args_info *ai);
int act_register(struct gengetopt_args_info *ai);
int act_register_name(struct gengetopt_args_info *ai);
int act_unregister(struct gengetopt_args_info *ai);
int act_unregister_name(struct gengetopt_args_info *ai);
int act_path(struct gengetopt_args_info *ai);
int act_get(struct gengetopt_args_info *ai);
int act_set(struct gengetopt_args_info *ai);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc == 1)
    {
        cmdline_parser_print_help();
        return 0;
    }

    struct gengetopt_args_info ai;
    if (cmdline_parser(argc, argv, &ai) != 0) 
        return 1;

    if (ai.help_given)
    {
        cmdline_parser_print_help();
        return 0;
    }
    else if (ai.version_given)
    {
        cmdline_parser_print_version();
        return 0;
    }

    if (smm_get_root() == NULL)
    {
        printf("Error: SMM_ROOT_DIRECTORY environment variable not set.");
        return 3;
    }

    if (ai.init_given) { return act_init(&ai); }
    else if (ai.new_given) { return act_new(&ai); }
    else if (ai.copy_given) { return act_copy(&ai); }
    else if (ai.move_given) { return act_move(&ai); }
    else if (ai.delete_given) { return act_delete(&ai); }
    else if (ai.register_given) { return act_register(&ai); }
    else if (ai.register_name_given) { return act_register_name(&ai); }
    else if (ai.unregister_given) { return act_unregister(&ai); }
    else if (ai.unregister_name_given) { return act_unregister_name(&ai); }
    else if (ai.path_given) { return act_path(&ai); }
    else if (ai.get_given) { return act_get(&ai); }
    else if (ai.set_given) { return act_set(&ai); }
    else
    {
        print_parsing_error("unknown");
        return 1;
    }

    return 0;
}

int act_init(struct gengetopt_args_info *ai)
{
    if (!smm_init_root())
        return EX_CANTCREAT;

    return 0;
}

int act_new(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_copy(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_move(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_delete(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_register(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_register_name(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_unregister(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_unregister_name(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_path(struct gengetopt_args_info *ai)
{
    char *root = smm_get_root();
    printf("%s", root);
    return 0;
}

int act_get(struct gengetopt_args_info *ai)
{
    return 0;
}

int act_set(struct gengetopt_args_info *ai)
{
    return 0;
}

