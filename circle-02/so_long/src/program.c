/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:12:58 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/program.h"

t_program	*program(void)
{
	static t_program	program;

	return (&program);
}

void	init_program(void)
{
	(program())->mlx_ptr = mlx_init();
	(*program()).layer = 1;
	(*program()).amount_draw = 0;
	(*program()).amount_objs = 0;
	(*object(First)) = NULL;
	(*object(Last)) = NULL;
	(program())->moves = 0;
}
