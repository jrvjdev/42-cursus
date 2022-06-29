/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:45:59 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 20:01:08 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	have_duplicates(t_list *list)
{
	t_list	*cursor;

	cursor = list->next;
	while (list && list->next)
	{
		if (list->content == cursor->content)
			return (1);
		if (cursor->next)
			cursor = cursor->next;
		else if (list->next->next)
		{
			list = list->next;
			cursor = list->next;
		}
		else
			return (0);
	}
	return (0);
}

int	is_integer(char *av)
{
	return (ft_atoi(av) >= -2147483648 && ft_atoi(av) <= 2147483647);
}

int	ft_is_already_sorted(int ac, char **av)
{
	int	index;

	index = 0;
	while (++index < ac - 1)
		if (ft_atoi(av[index]) >= ft_atoi(av[index + 1]))
			return (0);
	return (1);
}

int	lst_is_already_sorted(int ac, char **av)
{
	int	index;

	index = 0;
	while (++index < ac - 1)
		if (ft_atoi(av[index]) >= ft_atoi(av[index + 1]))
			return (0);
	return (1);
}

int	is_numeric(char *av)
{
	av += *av == '-';
	while (*av)
	{
		if (is_digit(*av))
			av++;
		else
			return (0);
	}
	return (1);
}

// int	have_errors(int ac, char **av, int op)
// {
// 	int	index;

// 	index = 0;
// 	while (av[++index])
// 		if (!is_numeric(av[index]) && !is_integer(av[index]))
// 			return (write(2, "Error\n", 6));
// 	if (have_duplicates(ac, av))
// 		return (write(2, "Error\n", 6));
// 	if (ft_is_already_sorted(ac, av) && op == 1 && ac > 2)
// 		return (write(1, "OK\n", 3));
// 	if (ft_is_already_sorted(ac, av) && op == 2)
// 		return (1);
// 	return (0);
// }
