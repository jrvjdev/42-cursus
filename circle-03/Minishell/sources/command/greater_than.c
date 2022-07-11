/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:24:13 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 09:34:19 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_greater_than(t_command *invoker, t_command *this)
{
	char	*name;

	printf("%s %s\n", __func__, this->name);
	if (_token(&name, this->next))
	{
		printf("Minishell: syntax error near unexpected token `%s'\n", name);
		_command_free_all();
		return ("");
	}
	_command_create_file(invoker, this, O_TRUNC);
	return ("");
}

void	command_greater_than(t_command *this)
{
	char	*name;

	printf("%s %s\n", __func__, this->name);
	if (!this->fd[0])
	{
		if (_token(&name, this->next))
		{
			printf("Minishell: syntax error near unexpected token `%s'\n", name);
			_command_free_all();
			return ;
		}
		if (this->next->next)
		{
			_command_create_file(this->next->next, this, O_TRUNC);
			this->next->next->function(this->next->next);
		}
		else
			_command_create_file(this, this, O_TRUNC);
		_command_free(this->next);
	}
	_command_close_file(this);
	_command_free(this);
}
