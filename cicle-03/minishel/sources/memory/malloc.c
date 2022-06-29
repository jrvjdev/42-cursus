/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:33:26 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/28 21:34:06 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/malloc.h"

t_malloc	**_malloc(int option)
{
	static t_malloc	*first;
	static t_malloc	*last;

	if (option)
		return (&last);
	return (&first);
}

void	add_maloc(t_malloc **new_malloc)
{
	if (!(*_malloc(0)))
		(*_malloc(0)) = (*new_malloc);
	else
	{
		(*_malloc(1)) = (*_malloc(0));
		while ((*_malloc(1))->next)
			(*_malloc(1)) = (*_malloc(1))->next;
		(*new_malloc)->prev = (*_malloc(1));
		(*_malloc(1))->next = (*new_malloc);
	}
	(*_malloc(1)) = (*new_malloc);
}

// return 0 if pointer have made a new malloc
// return 1 if pointer have been freed
int	free_malloc(void *ptr)
{
	if (ptr)
	{
		(*_malloc(1)) = (*_malloc(0));
		while ((*_malloc(1)))
		{
			if ((*_malloc(1))->ptr == ptr)
				break ;
			(*_malloc(1)) = (*_malloc(1))->next;
		}
		if (!(*_malloc(1)))
			return (1);
		free((*_malloc(1))->ptr);
		if ((*_malloc(1))->prev && (*_malloc(1))->next)
		{
			(*_malloc(1))->prev->next = (*_malloc(1))->next;
			(*_malloc(1))->next->prev = (*_malloc(1))->prev;
		}
		else if (!(*_malloc(1))->prev)
			(*_malloc(0)) = (*_malloc(0))->next;
		free((*_malloc(1)));
	}
	return (0);
}

void	free_all_maloc(void)
{
	(*_malloc(1)) = (*_malloc(0));
	while ((*_malloc(1))->next)
		(*_malloc(1)) = (*_malloc(1))->next;
	while ((*_malloc(1)))
	{
		free_malloc((*_malloc(1))->ptr);
		(*_malloc(1)) = (*_malloc(0));
		while ((*_malloc(1))->next)
			(*_malloc(1)) = (*_malloc(1))->next;
	}
}

void	*new_malloc(size_t __size)
{
	unsigned char	*buf;
	t_malloc	*node;

	node = malloc(sizeof(t_malloc));
	if (!node)
		free_all_maloc();
	node->prev = NULL;
	node->next = NULL;
	node->ptr = malloc(__size);
	if (!node->ptr)
	{
		free(node);
		free_all_maloc();
	}
	buf = (unsigned char *)node->ptr;
	while (__size--)
		*buf++ = (unsigned char)0;
	add_maloc(&node);
	return (node->ptr);
}
