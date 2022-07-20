#include "../../includes/command.h"

char *command_pre_cd(t_token *command)
{
	printf("command pre cd\n");
	if (command->next)
		command->next->pre_function(command->next);
	//_memory().free(command->name);
	_command().delete(command);
	return ("name");
}

void command_cd(t_token *command)
{
	printf("command cd\n");
	if (command->next)
		command->next->pre_function(command->next);
	//_memory().free(command->name);
	_command().delete(command);
}