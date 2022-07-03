/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/03 12:01:15 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	// printf("%i\n", _char().is_whitespace('	'));

	// char str[]="all this way";
	// printf("new =%s\n", _string_dup_at(str, 5));
	

	int		name;
	char	*line;
	char	**cmds;

	if (ac != 1)
		return (0);
	(void)av;
	// while (*env)
	// 	init_env(new_hashmap(*env++));
	while (1)
	{
		line = readline(ft_prompt());
		if (_string().equals(line, "exit"))
			break;
		if (_string().length(line) == 0)
			continue;
		else
			add_history(line);
		(cmds) = buffer_into_array(line);
		print_arrays(cmds);
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
		// execute_command();
		free(line);
		// free_arrays(cmds);
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

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

// 	str = "helloworld";
// 	char *str2 = "enf of";
// 	_string_cat(str, str2);
// 	printf("%s\n", str);

	
// 	_memory().free(str);
// 	return (0);
// }

