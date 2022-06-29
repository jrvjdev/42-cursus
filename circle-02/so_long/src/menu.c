/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:03:58 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 01:32:34 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/menu.h"

void	draw_number(int number, int *x)
{
	if (number < 0)
		destroy_all_object();
	if (number > 9)
		draw_number(number / 10, x);
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->animator.animation[down].\
		frames[number % 10], ((*x)++) * 64, (*object(Last))->position.y);
}

void	int_to_str(int nb, char ptr[10], int *index)
{
	if (nb > 9)
		int_to_str(nb / 10, ptr, index);
	ptr[(*index)++] = (nb % 10) + 48;
}

static void	draw(void)
{
	int			i;
	static int	t;
	int			len;
	char		str[10];

	i = 20;
	len = 0;
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->animator.animation[idle].frames[0], \
		128, (*object(Last))->position.y);
	mlx_put_image_to_window(program()->mlx_ptr,
		window()->win_ptr, (*object(Last))->animator.animation[up].frames[0], \
		900, (*object(Last))->position.y);
	draw_number(map()->time, &i);
	int_to_str(map()->steps, str, &len);
	write(1, "steps ", 6);
	write(1, str, len);
	write(1, "\n", 1);
	if (!t++)
		map()->time--;
	if (t > 50)
		t = 0;
	i = 8;
	draw_number(map()->steps, &i);
}

void	make_panel(void)
{
	t_vector2	v;

	v = new_vector2(-1, 0);
	while (++v.x < window()->size.x / 64)
		new_pole(new_vector2(v.x * 64, 0), "xpm/wall1.xpm");
	new_pole(new_vector2(0, 64), "xpm/wall1.xpm");
	new_pole(new_vector2(window()->size.x - 64, 64), "xpm/wall1.xpm");
	v = new_vector2(-1, 2);
	while (++v.x < window()->size.x / 64)
		new_pole(new_vector2(v.x * 64, 128), "xpm/wall1.xpm");
}

void	new_menu(t_vector2 position)
{
	t_object		*ob;
	t_sprite		sprite;
	t_vector2		vector2;

	make_panel();
	ob = new_object(position);
	ob->type = 10;
	ob->animator.size = 3;
	ob->collider = new_collider(7, 37, 29, 52);
	sprite = new_sprite("xpm/steps.xpm");
	vector2 = new_vector2(1, 1);
	ob->animator.animation[idle] = new_animation(10, sprite, vector2, "0");
	destroy_sprite(&sprite);
	sprite = new_sprite("xpm/time.xpm");
	vector2 = new_vector2(1, 1);
	ob->animator.animation[up] = new_animation(10, sprite, vector2, "0");
	destroy_sprite(&sprite);
	sprite = new_sprite("xpm/numbers.xpm");
	vector2 = new_vector2(10, 1);
	ob->animator.animation[down] = new_animation(10, sprite, vector2, \
	"0,1,2,3,4,5,6,7,8,9");
	destroy_sprite(&sprite);
	ob->draw = draw;
	(*line(Last)) = (*line(First));
	read_line(new_vector2(-1, 3));
}
