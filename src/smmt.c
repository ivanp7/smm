#include <locale.h>
#include <wchar.h>

#include "libsmm.h"
#include "smmt.h"
#include "smmt_cmdline.ggo.h"

static void print_parsing_error(const char *reason)
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

void act_new(struct gengetopt_args_info *ai);
void act_path(struct gengetopt_args_info *ai);
void act_copy(struct gengetopt_args_info *ai);
void act_move(struct gengetopt_args_info *ai);
void act_delete(struct gengetopt_args_info *ai);
void act_register(struct gengetopt_args_info *ai);
void act_register_name(struct gengetopt_args_info *ai);
void act_unregister(struct gengetopt_args_info *ai);
void act_unregister_name(struct gengetopt_args_info *ai);
void act_path(struct gengetopt_args_info *ai);
void act_get(struct gengetopt_args_info *ai);
void act_set(struct gengetopt_args_info *ai);

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
    {
        return 1;
    }

    if (ai.help_given)
    {
        if (argc > 2)
        {
            print_parsing_error("too_many");
            return 1;
        }

        cmdline_parser_print_help();
        return 0;
    }
    else if (ai.version_given)
    {
        if (argc > 2)
        {
            print_parsing_error("too_many");
            return 1;
        }

        cmdline_parser_print_version();
        return 0;
    }

    if (smm_get_root() == NULL)
    {
        printf("Error: SMM_ROOT_DIRECTORY environment variable not set.");
        return 1;
    }

    if (ai.new_given) { act_new(&ai); }
    else if (ai.copy_given) { act_copy(&ai); }
    else if (ai.move_given) { act_move(&ai); }
    else if (ai.delete_given) { act_delete(&ai); }
    else if (ai.register_given) { act_register(&ai); }
    else if (ai.register_name_given) { act_register_name(&ai); }
    else if (ai.unregister_given) { act_unregister(&ai); }
    else if (ai.unregister_name_given) { act_unregister_name(&ai); }
    else if (ai.path_given) { act_path(&ai); }
    else if (ai.get_given) { act_get(&ai); }
    else if (ai.set_given) { act_set(&ai); }
    else
    {
        print_parsing_error("unknown");
        return 1;
    }

    return 0;
}

void act_new(struct gengetopt_args_info *ai)
{
}

void act_copy(struct gengetopt_args_info *ai)
{
}

void act_move(struct gengetopt_args_info *ai)
{
}

void act_delete(struct gengetopt_args_info *ai)
{
}

void act_register(struct gengetopt_args_info *ai)
{
}

void act_register_name(struct gengetopt_args_info *ai)
{
}

void act_unregister(struct gengetopt_args_info *ai)
{
}

void act_unregister_name(struct gengetopt_args_info *ai)
{
}

void act_path(struct gengetopt_args_info *ai)
{
    char *root = smm_get_root();
    printf("%s", root);
}

void act_get(struct gengetopt_args_info *ai)
{
}

void act_set(struct gengetopt_args_info *ai)
{
}

