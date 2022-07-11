/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Less_than.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:24:13 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/08 21:51:14 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_less_than(t_command *invoker, t_command *this)
{
	char	*name;

	if (_token(&name, this->next))
	{
		printf("Minishell: syntax error near unexpected token `%s'\n", name);
		_command_free_all();
		return (NULL);
	}
	if (_command_create_file(invoker, this, O_TRUNC))
		return (NULL);
	return (this->name);
}

void	command_less_than(t_command *this)
{
	char	*name;

	if (!this->fd[0])
	{
		if (!_token(&name, this->next) || _token(&name, this->next->next))
		{
			printf("Minishell: syntax error near unexpected token `%s'\n", name);
			_command_free_all();
			return ;
		}
		if (this->next->next)
		{
			if (_command_create_file(this->next->next, this, O_TRUNC))
				return ;
			this->next->next->function(this->next->next);
		}
		else
			if (_command_create_file(this, this, O_TRUNC))
				return ;
		_command_free(this->next);
	}
	// _command_close_file(this);
	_command_free(this);
}
