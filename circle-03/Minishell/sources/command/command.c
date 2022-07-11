/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:20:16 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 15:42:36 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

t_command **_command(void)
{
	static t_command *command;

	return (&command);
}

int size_of_command_list(t_command *command)
{
	if (command)
		return (1 + size_of_command_list(command->next));
	else
		return (0);
}

int _command_add(t_command **list, t_command *command)
{
	if (!list)
		return (0);
	if (!*list)
	{
		*list = command;
		return (1);
	}
	else if (_command_add(&((*list)->next), command))
		command->prev = (*list);
	return (0);
}

int _command_remove(t_command **list, t_command *command)
{
	t_command *prev;
	t_command *next;

	if (!list || !*list)
		return (0);
	if ((*list) == command)
	{
		if ((*list)->prev && (*list)->next)
		{
			prev = (*list)->prev;
			next = (*list)->next;
			prev->next = next;
			next->prev = prev;
		}
		else if (!(*list)->prev)
		{
			(*list) = (*list)->next;
			if ((*list))
				(*list)->prev = NULL;
		}
		else
			(*list)->prev->next = NULL;
		return (1);
	}
	return (_command_remove(&((*list)->next), command));
}

int _command_free(t_command *command)
{
	if (_command_remove(_command(), command))
	{
		free(command);
		return (1);
	}
	return (0);
}

void _command_free_all(void)
{
	while ((*_command()))
		_command_free((*_command()));
}

t_command *init_command(char *cmds, t_pre_function pre_function, t_function function)
{
	t_command *command;

	command = (t_command *)malloc(sizeof(t_command));
	command->name = parse_array(cmds);
	command->pre_function = pre_function;
	command->function = function;
	command->next = NULL;
	command->prev = NULL;
	_command_add(_command(), command);
	return (command);
}

void execute_command(void)
{
	//(*(*_command())->function)((*_command()));
	while ((*_command())) (*(*_command())->function)((*_command()));
}





// t_command	**_command(int option)
// {
// 	static t_command	*first;
// 	static t_command	*last;

// 	if (option)
// 		return (&last);
// 	return (&first);
// }

// int	size_of_command(void)
// {
// 	int	i;

// 	i = 0;
// 	(*_command(1)) = (*_command(0));
// 	while ((*_command(1)))
// 	{
// 		i++;
// 		(*_command(1)) = (*_command(1))->next;
// 	}
// 	return (i);
// }

// void	_command_add(t_command **new_command)
// {
// 	if (!(*_command(0)))
// 		(*_command(0)) = (*new_command);
// 	else
// 	{
// 		(*_command(1)) = (*_command(0));
// 		while ((*_command(1))->next)
// 			(*_command(1)) = (*_command(1))->next;
// 		(*new_command)->prev = (*_command(1));
// 		(*_command(1))->next = (*new_command);
// 	}
// 	(*_command(1)) = (*new_command);
// }

// int _command_free(t_command *command)
// {
// 	if (command)
// 	{
// 		(*_command(1)) = (*_command(0));
// 		while ((*_command(1)))
// 		{
// 			if ((*_command(1)) == command)
// 				break;
// 			(*_command(1)) = (*_command(1))->next;
// 		}
// 		if (!(*_command(1)))
// 			return (1);
// 		if ((*_command(1))->prev && (*_command(1))->next)
// 		{
// 			(*_command(1))->prev->next = (*_command(1))->next;
// 			(*_command(1))->next->prev = (*_command(1))->prev;
// 		}
// 		else if (!(*_command(1))->prev)
// 		{
// 			(*_command(0)) = (*_command(0))->next;
// 			if ((*_command(0)))
// 				(*_command(0))->prev = NULL;
// 		}
// 		else if (!(*_command(1))->next)
// 			(*_command(1))->prev->next = NULL;
// 		_memory().free((*_command(1)));
// 		(*_command(1)) = (*_command(0));
// 	}
// 	return (0);
// }

// void _command_free_all(void)
// {
// 	while ((*_command(0)))
// 		_command_free((*_command(0)));
// }

// t_command *init_command(char *cmds, t_pre_function pre_function, t_function function)
// {
// 	t_command *command;

// 	command = (t_command *)_memory().malloc(sizeof(t_command));
// 	command->name = parse_array(cmds);
// 	command->pre_function = pre_function;
// 	command->function = function;
// 	command->next = NULL;
// 	command->prev = NULL;
// 	_command_add(&command);
// 	return (command);
// }

// void execute_command(void)
// {
// 	while ((*_command(0))) (*(*_command(0))->function)((*_command(0)));
// }