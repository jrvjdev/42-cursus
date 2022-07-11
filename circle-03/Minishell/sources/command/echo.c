/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:14:26 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/08 21:32:07 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_echo(t_command *invoker, t_command *this)
{
	char	*name;

	(void)invoker;
	name = this->name;
	if (!_token(&name, this->next))

		_command_free(this);
	return (name);
}

void	command_echo(t_command *this)
{
	if (this->next)
	{
		if (_string().equals(this->next->name, "-n"))
		{
			if (this->next->next)
				printf("%s\n", this->next->next->pre_function(this, this->next->next));
			// _command_free(this->next);
		}
		else
			printf("%s\n", this->next->pre_function(this, this->next));
	}
	_command_free(this);
}
