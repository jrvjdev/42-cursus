/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/02 11:37:52 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	(void)env;
// 	printf("%i\n", _char().is_whitespace('	'));
// 	// int		name;
// 	// char	*line;
// 	// char	**cmds;

// 	// if (ac != 1)
// 	// 	return (0);
// 	// (void)av;
// 	// while (*env)
// 	// 	init_env(new_hashmap(*env++));
// 	// while (1)
// 	// {
// 	// 	line = readline("$> ");
// 	// 	(cmds) = line_into_array(line); //this i HAVE 95% cmds ≠
// 	// 	while (*cmds)
// 	// 	{
// 	// 		name = _names(*cmds);
// 	// 		if (name >= 0)
// 	// 			init_command(*cmds, _functions(name)); //to-do     
// 	// 		else
// 	// 		{
// 	// 			///accessee8)
// 	// 		}
// 	// 		cmds++;
// 	// 	}
// 	// 	execute_command();
// 	// 	free(line);
// 	// }
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int	main(void)
// {
// 	char	*str;

// 	str = (char *) _memory().malloc(15);
// 	(_string().copy)(str, "tutorialspoint");
// 	printf("String = %s,  Address = %p\n", str, str);

// 	str = (char *) _memory().realloc(str, 25);
// 	printf("String = %s,  Address = %p\n", str, str);
// 	(_string().cat)(str, ".com");
// 	printf("String = %s,  Address = %p\n", str, str);

// 	_memory().free(str);
// 	return (0);
// }

int	main(void)
{
	char	*str = _string().itoa(-123);

	printf("%s\n", str);
	return (0);
}
