/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:20:16 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/28 23:14:44 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

int	_names(char	*name)
{
	unsigned long	index;
	static char		_names[7][10] = {
		"cd",
		"env",
		"pwd",
		"echo",
		"exit",
		"unset",
		"export",
	};

	index = 0;
	while (index < (sizeof(_names) / sizeof(*_names)))
	{
		if (equals(name, _names[index]) > 0)
			break ;
		index++;
	}
	return (index);
}

t_function	*_functions(int index)
{
	static t_function	functions[7] = {
		&command_cd,
		&command_env,
		&command_pwd,
		&command_echo,
		&command_exit,
		&command_unset,
		&command_export
	};

	return (&functions[index]);
}

t_command	**_command(void)
{
	static t_command	*command;

	return (&command);
}

void	init_command(char *name, t_function *functions)
{
	t_command	**command;

	command = _command();
	if (!*command)
	{
		*command = (t_command *)malloc(sizeof(t_command));
		(*command)->name = name;
		(*command)->functions = functions;
	}
	else
	{
		while ((*command)->next)
			command = &(*command)->next;
		(*command)->next = (t_command *)malloc(sizeof(t_command));
		(*command)->next->name = name;
		(*command)->next->functions = functions;
	}
}

void	execute_command(void)
{
	t_command	**command;

	command = _command();
	while ((*command)->next)
	{
		(*(*command)->functions)("");
		command = &(*command)->next;
	}
}
