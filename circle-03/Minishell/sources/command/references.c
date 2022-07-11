/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   references.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 08:19:04 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 00:00:38 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

int	_names(char	*name)
{
	unsigned long	index;
	static char		_names[11][7] = {
		"cd",
		"echo",
		"env",
		"exit",
		"export",
		">>",
		">",
		"<<",
		"<",
		"pwd",
		"unset"
	};

	index = 0;
	while (index < (sizeof(_names) / sizeof(*_names)))
	{
		if (_string().equals(name, _names[index]) > 0)
			return (index);
		index++;
	}
	return (-1);
}

char	*_token(char **name, t_command *command)
{
	unsigned long	index;
	static char		_names[10][3] = {
		"||",
		"|",
		">>",
		">",
		"<<",
		"<",
		"&&",
		"&",
		";;",
		";"
	};

	*name = NULL;
	if (!command)
	{
		*name = "newline";
		return ("newline");
	}
	index = -1;
	while (++index < (sizeof(_names) / sizeof(*_names)))
	{
		if (_string().beginning_equals(command->name, _names[index]) > 0)
		{
			*name = _names[index];
			return (*name);
		}
	}
	return (NULL);
}

t_pre_function	_pre_functions(int index)
{
	static t_pre_function	functions[11] = {
		command_pre_cd,
		command_pre_echo,
		command_pre_env,
		command_pre_exit,
		command_pre_export,
		command_pre_greater_than_append,
		command_pre_greater_than,
		command_pre_less_than_append,
		command_pre_less_than,
		command_pre_pwd,
		command_pre_unset
	};

	if (index < 0)
		return (command_pre_system);
	return (functions[index]);
}

t_function	_functions(int index)
{
	static t_function	functions[11] = {
		command_cd,
		command_echo,
		command_env,
		command_exit,
		command_export,
		command_greater_than_append,
		command_greater_than,
		command_less_than_append,
		command_less_than,
		command_pwd,
		command_unset
	};

	if (index < 0)
		return (command_system);
	return (functions[index]);
}
