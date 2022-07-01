/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 10:46:42 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	int		name;
	char	*line;
	char	**cmds;

	if (ac != 1)
		return (0);
	(void)av;
	while (*env)
		init_env(new_hashmap(*env++));
	while (1)
	{
		line = readline("$> ");
		(cmds) = line_into_array(line); //this i HAVE 95% cmds ≠
		while (*cmds)
		{
			name = _names(*cmds);
			if (name >= 0)
				init_command(*cmds, _functions(name)); //to-do     
			else
			{
				///accessee8)
			}
			cmds++;
		}
		execute_command();
		free(line);
	}
	return (0);
}

git@github.com:jrvjdev/42-cursus.git

mkdir minishellpractice
clone git  git@github.com:jrvjdev/42-cursus.git

minishell IOC_DIRMASK
git add /circle_03/ minishjel
