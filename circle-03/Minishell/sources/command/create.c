#include "../../includes/command.h"

void _command_create(char *cmds, t_pre_function pre_function, t_function function)
{
	(void)cmds;
	(void)pre_function;
	(void)function;
	t_token *command;

	command = _memory().malloc(sizeof(t_token));
	command->prev = NULL;
	command->next = NULL;
	command->error = 0;
	command->name = _string().dup(cmds);
	command->pre_function = pre_function;
	command->function = function;
	_list().add_node((void **)_command().list(), command);
}