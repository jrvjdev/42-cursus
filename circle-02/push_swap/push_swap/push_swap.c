/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:46:06 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 20:35:12 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **stack, int *index, char **av)
{
	int		string;
	int		length;

	length = -1;
	while ((*av)[++length])
	{
		if ((!is_digit((*av)[length]) && !is_white_space((*av)[length])) \
		|| !is_integer(*av))
		{
			lst_clear(stack);
			exit(write(2, "Error\n", 6));
		}
	}
	string = ft_split_atoi(stack, av);
	if (string == -2)
	{
		lst_clear(stack);
		exit(write(2, "Error\n", 6));
	}
	*av += string >= 0;
	*index += string < 0;
}

int	main(int ac, char **av)
{
	int		index;
	t_list	*stack_a;
	t_list	*stack_b;

	index = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (write(2, "Error\n", 6));
	while (index < ac)
		fill_stack(&stack_a, &index, &(av[index]));
	printf("XXXXX: %d\n", ac);
	if (have_duplicates(stack_a))
		return (write(2, "Error\n", 6));
	if (!lst_sorted(stack_a))
	{
		if (ac < 4)
			swap(&stack_a, 1);
		else if (ac < 5)
			sort1(&stack_a);
		else
			sort2(&stack_a, &stack_b, ac);
	}
	lst_clear_all(&stack_a, &stack_b);
	return (0);
}
