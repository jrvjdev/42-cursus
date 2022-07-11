/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:28:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/08 21:31:43 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_cd(t_command *invoker, t_command *this)
{
	char	*name;

	(void)invoker;
	printf("%s %s\n", __func__, invoker->name);
	name = this->name;
	if (this->next)
		this->next->pre_function(this, this->next);
	_command_free(this);
	return (name);
}

void	command_cd(t_command *this)
{
	printf("%s\n", this->name);
	if (this->next)
		this->next->pre_function(this, this->next);
	_command_free(this);
}
