#include "../includes/minishell.h"

void do_with_ac(int ac, char **av)
{
    char *line;
    char **cmds;
    int index;

    for (int i = 1; i < ac; i++)
    {
        line = av[i];
        printf("LINE= %s\n", line);
        if (_string().length(line) > 0)
        {
            if (_string().equals(line, "exit"))
                break;
            add_history(line);
            cmds = buffer_into_array(line);
            // cmds = _string().split_char(line, ' ');
            while (*cmds)
            {
                index = _names(*cmds);
                printf("%s- %i\n", *cmds, index);
                _command().create(*(cmds), _pre_functions(index), _functions(index));
                cmds++;
            }
        }
        _command().execute();
        _memory().free(cmds);
        cmds = 0;
    }
    printf("clean-exit_ac\n");
    exit(1);
}

int main(int ac, char **av, char **env)
{
    int index;
    char *line;
    char **cmds;

    if (ac != 1)
        do_with_ac(ac, av);
    (void)env;
    index = 1;
    while (1)
    {
        line = readline("$> ");
        printf("READLINE= %s\n", line);
        if (_string().length(line) > 0)
        {
            if (_string().equals(line, "exit"))
                break;
            add_history(line);
            cmds = buffer_into_array(line);
            // cmds = _string().split_char(line, ' ');
            while (_string().length(*cmds) > 0)
            {
                index = _names(*cmds);
                // printf("%s- %i\n", *cmds, index);
                _command().create(*(cmds), _pre_functions(index), _functions(index));
                cmds++;
            }
        }
        _command().execute();
        _memory().free(cmds);
        cmds = 0;
    }
    //    system("leaks minishell");
    printf("clean-exit\n");
    return (0);
}

// '$HOME'
// "ls" -> ls
// "'ls'" -> 'ls'(return -1) error