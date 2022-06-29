/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:41:56 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/29 16:41:58 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>

typedef struct s_malloc
{
	void			*ptr;
	struct s_malloc	*next;
	struct s_malloc	*prev;
}	t_malloc;

void	*new_malloc(size_t __size);
int		free_malloc(void *ptr);
void	free_all_malloc(void);

#endif
