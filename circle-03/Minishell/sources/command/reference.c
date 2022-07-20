#include "../../includes/command.h"

t_command _command(void)
{
	static t_command _command = {
		_commands_list,
		_command_execute,
		_command_delete,
		_command_create,
	};

	return (_command);
}

t_token **_commands_list(void)
{
	static t_token *command;

	return (&command);
}

int _names(char *name)
{
	unsigned long index;
	static char _names[1][2] = {
		"cd"
	};
	printf("evalutate_name %s|\n", name);
	index = 0;
	while (index < (sizeof(_names) / sizeof(*_names)))
	{
		if (_string().equals(name, _names[index]) > 0)
			return (index);
		index++;
	}
	return (-1);
}

t_pre_function _pre_functions(int index)
{
	static t_pre_function functions[8] = {
		command_pre_cd
	};

	if (index < 0)
		return (NULL);
	return (functions[index]);
}

t_function _functions(int index)
{
	static t_function functions[8] = {
		command_cd
	};

	if (index < 0)
		return (NULL);
	return (functions[index]);
}
