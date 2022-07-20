#include "../../includes/command.h"

int _command_delete(t_token *command)
{
	if (!_command_check(_command().list(), command))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	_list().remove_node((void **)_command().list(), command);
	_memory().free(command);
	return (0);
}