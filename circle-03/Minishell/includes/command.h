/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:59 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/06 00:33:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

# include "string.h"
# include "list.h"
# include "memory.h"

typedef struct s_token		t_token;
typedef struct s_command	t_command;
typedef void 				(*t_function)(t_token *command);
typedef char 				*(*t_pre_function)(t_token *command);

struct	s_token
{
	t_token 		*prev;
	t_token 		*next;
	int				error;
	int				cmd;
	int				fd[2];
	char			*name;
	t_pre_function	pre_function;
	t_function		function;
};

struct s_command
{
	t_token 	**(*list)(void);
	void 		(*execute)(void);
	int 		(*delete)(t_token *command);
	void 		(*create)(char *cmds, t_pre_function pre_function,
					t_function function);
};

t_command 		_command(void);

int				_names(char *name);
t_function		_functions(int index);
t_pre_function	_pre_functions(int index);

t_token			**_commands_list(void);
void			_command_execute(void);
int 			_command_delete(t_token *command);
t_token			*_command_check(t_token **list, t_token *command);
void			_command_create(char *cmds, t_pre_function pre_function, \
					t_function function);

void 			command_cd(t_token *command);
char 			*command_pre_cd(t_token *command);

#endif
