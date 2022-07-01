/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:20:16 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 10:07:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

t_command	**_command(int option)
{
	static t_command	*first;
	static t_command	*last;

	if (option)
		return (&last);
	return (&first);
}

ls | grep makefile
output &> grep makefile



void	add_command(t_command **new_command)
{
	if (!(*_command(0)))
		(*_command(0)) = (*new_command);
	else
	{
		(*_command(1)) = (*_command(0));
		while ((*_command(1))->next)
			(*_command(1)) = (*_command(1))->next;
		(*new_command)->prev = (*_command(1));
		(*_command(1))->next = (*new_command);
	}
	(*_command(1)) = (*new_command);
}

void	init_command(char *name, t_function functions)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	command->name = name;
	command->functions = functions;
	command->next = NULL;
	command->prev = NULL;
	add_command(&command);
}

void	execute_command(void)
{
	while ((*_command(0)))
	{
		(*_command(1)) = (*_command(0));
		(*_command(0)) = (*_command(0))->next;
		(*(*_command(1))->functions)();
		free_malloc((*_command(1)));
	}
}
