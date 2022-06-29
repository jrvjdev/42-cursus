/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/28 23:11:40 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	char	*line;

	if (ac != 1)
		return (0);
	(void)av;
	while (*env)
		init_env(new_hashmap(*env++));
	while (1)
	{
		line = readline("$> ");
		printf("%s\n",line);
		init_command(line, _functions(_names(line)));
		free(line);
	}
	return (0);
}
