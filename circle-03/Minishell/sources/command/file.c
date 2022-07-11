/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:13:32 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 00:13:57 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

// t_file	_file(char *name)
// {
// 	static t_file	file = {
		
// 	};

// 	return (file);
// }

int	_command_create_file(t_command *invoker, t_command *this, int mode)
{
	this->fd[0] = open(this->next->name, O_CREAT | O_WRONLY | mode, 0644);
	if (this->fd[0] < 0)
	{
		printf("Minishell: %s: Permission denied\n", this->next->name);
		_command_free(this->next);
		_command_free(invoker);
		_command_free(this);
		return (1);
	}
	this->fd[1] = dup(1);
	dup2(this->fd[0], 1);
	return (0);
}

void	_command_close_file(t_command *this)
{
	dup2(this->fd[1], 1);
	close(this->fd[0]);
}
