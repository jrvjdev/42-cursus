/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 16:35:21 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		printf("%s\n", line);
		init_command(line, _functions(_names(line)));
		free(line);
	}
	return (0);
}