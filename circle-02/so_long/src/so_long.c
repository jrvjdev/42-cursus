/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:53:30 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 12:50:04 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	init_all();
	load_map(av[1]);
	new_window(window()->size, "so_long");
	mlx_hook((window())->win_ptr, 2, 1, key_down, NULL);
	mlx_hook((window())->win_ptr, 3, 1, key_up, NULL);
	mlx_loop_hook((program())->mlx_ptr, loop_hook, NULL);
	mlx_loop((program())->mlx_ptr);
	return (0);
}
