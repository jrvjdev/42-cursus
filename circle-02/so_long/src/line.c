/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:33:20 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/16 01:32:25 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/line.h"

void	free_line(void)
{
	(*line(Last)) = (*line(First));
	while ((*line(Last)))
	{
		(*line(First)) = (*line(First))->next;
		free_maloc((*line(Last))->str);
		free_maloc((*line(Last)));
		(*line(Last)) = (*line(First));
	}
}

int	check_line(char *str, int ops)
{
	if (ops)
	{
		if (*str && *str == '1' && str[str_len(str) - 1] == '1')
			return (1);
		return (0);
	}
	else
	{
		if (*str && *str == '1')
			return (1 * check_line(str + 1, ops));
		else
			return (*str == 0 || *str == '\n');
	}
}

t_line	*add_line(t_line **first, t_line **last, t_line *new_line)
{
	if (!(*first))
		(*first) = new_line;
	else
		(*last)->next = new_line;
	(*last) = new_line;
	return (new_line);
}

t_line	*new_line(char *str)
{
	t_line	*temp;

	if (!str)
		return (NULL);
	temp = new_maloc(sizeof(t_line));
	temp->str = str;
	return (temp);
}

void	read_line(t_vector2 v)
{
	while ((*line(Last)))
	{
		if ((*line(Last))->str[++v.x])
		{
			if ((*line(Last))->str[v.x] == 'P' && map()->player > 0)
			{
				new_player(new_vector2(v.x * 64, v.y * 64), "xpm/per.xpm");
				map()->player = -1;
			}
			else if ((*line(Last))->str[v.x] == 'E')
				new_exit(new_vector2(v.x * 64, v.y * 64), "xpm/exit.xpm");
			else if ((*line(Last))->str[v.x] == 'C')
				new_pokebola(new_vector2(v.x * 64, v.y * 64), "xpm/pokeb.xpm");
			else if ((*line(Last))->str[v.x] == '1')
				new_pole(new_vector2(v.x * 64, v.y * 64), "xpm/wall1.xpm");
			else if ((*line(Last))->str[v.x] == '0' && !rando(-20, 20))
				new_enemy(new_vector2(v.x * 64, v.y * 64), "xpm/jessie.xpm");
		}
		else
		{
			v.x = (v.y++ == -1) - 1;
			(*line(Last)) = (*line(Last))->next;
		}
		(window())->size.y = v.y * 64;
	}
}
