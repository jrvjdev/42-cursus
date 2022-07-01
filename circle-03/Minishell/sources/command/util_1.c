/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 08:19:04 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 12:20:34 by joaribei         ###   ########.fr       */
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
		if (_string().equals(name, _names[index]) > 0)
			return (index);
		index++;
	}
	return (-1);
}

t_function	_functions(int index)
{
	static t_function	functions[7] = {
		command_cd,
		command_env,
		command_pwd,
		command_echo,
		command_exit,
		command_unset,
		command_export
	};

	return (functions[index]);
}
