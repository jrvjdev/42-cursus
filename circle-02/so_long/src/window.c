/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:55:14 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:08:57 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

t_window	*window(void)
{
	static t_window	window;

	return (&window);
}

int	ft_close(void)
{
	destroy_all_object();
	return (1);
}

void	new_window(t_vector2 size, char *title)
{
	(window())->win_ptr = mlx_new_window((program())->mlx_ptr, \
	size.x, size.y, title);
	if (!window()->win_ptr)
		destroy_all_object();
	mlx_hook(window()->win_ptr, 17, 0, ft_close, 0);
}
