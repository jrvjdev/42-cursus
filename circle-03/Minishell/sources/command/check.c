#include "../../includes/command.h"

t_token *_command_check(t_token **list, t_token *command)
{
	if (list && *list && command)
	{
		if (command == *list)
			return (command);
		return (_command_check(&((*list)->next), command));
	}
	return (NULL);
}