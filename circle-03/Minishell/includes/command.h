/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:59 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 07:52:59 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <stdio.h>

# include "string.h"

typedef void	(*t_function)(void);

typedef struct s_command
{
	int					fd[2];
	char				*name;
	t_function			functions;
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

int			_names(char	*name);
t_function	_functions(int index);

void		command_cd(void);
void		command_env(void);
void		command_pwd(void);
void		command_echo(void);
void		command_exit(void);
void		command_unset(void);
void		command_export(void);

void		execute_command(void);
void		init_command(char *name, t_function functions);

#endif
