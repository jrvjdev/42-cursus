/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:22:35 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/08 21:32:17 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_exit(t_command *invoker, t_command *this)
{
	char	*name;

	(void)invoker;
	name = this->name;
	_command_free(this);
	return (name);
}

void	command_exit(t_command *this)
{
	printf("command %s\n", this->name);
	exit(0);
}
