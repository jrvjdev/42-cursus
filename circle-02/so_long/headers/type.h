/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:52:57 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/15 23:35:11 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define CORECTION_X 12
# define CORECTION_Y 8

typedef void	(*t_draw)(void);
typedef void	(*t_update)(void);

typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	float					vertexes[8];
	struct s_mlx_img_list	*next;
}	t_mlx_img_list;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_sprite
{
	t_vector2		size;
	t_mlx_img_list	*img_ptr;
	char			*pixels;
	int				endian;
	int				size_line;
	int				bits_per_pixel;
}	t_sprite;

typedef enum e_animation_state
{
	idle,
	up,
	down,
	left,
	right
}	t_animation_state;

typedef struct s_animation
{
	int					size;
	int					index;
	int					speed;
	int					time;
	int					loop;
	t_mlx_img_list		*frames[12];
}	t_animation;

typedef struct s_animator
{
	int					size;
	t_animation_state	state;
	t_animation			animation[5];
}	t_animator;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_collider
{
	t_bool		trigger;
	int			x;
	int			y;
	int			w;
	int			h;
}	t_collider;

typedef enum e_type_object
{
	Player,
	Enemy,
	Pole,
	Exit,
	Fence,
	Collectible,
	Scenery
}	t_type_object;

typedef struct s_object
{
	char			type;
	char			collision_types[4];
	int				layer;
	t_draw			draw;
	t_update		update;
	t_vector2		size;
	t_vector2		position;
	t_animator		animator;
	int				collectible;
	struct s_object	*data;
	t_collider		*collider;
	t_mlx_img_list	*sprites;
	struct s_object	*collided;
	struct s_object	*prev;
	struct s_object	*next;
}	t_object;

typedef struct s_scenery
{
	t_vector2		size;
	t_animator		tiles;
}	t_scenery;

typedef struct s_index
{
	int	x;
	int	y;
}	t_index;

typedef enum e_option
{
	First,
	Last
}	t_option;

typedef enum e_key_value
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
}	t_key_value;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}	t_key;

typedef struct s_window
{
	void		*win_ptr;
	t_vector2	size;
}	t_window;

typedef struct s_map
{
	int			line;
	int			column;
	int			top;
	int			mid;
	int			down;
	int			exit;
	int			collectible;
	int			player;
	int			time;
	int			steps;
}	t_map;

typedef struct s_program
{
	void		*mlx_ptr;
	t_vector2	corection;
	int			layer;
	int			amount_draw;
	int			amount_objs;
	int			moves;
}	t_program;

typedef struct s_maloc
{
	void			*ptr;
	struct s_maloc	*next;
	struct s_maloc	*prev;
}	t_maloc;

typedef struct s_line
{
	char			*str;
	struct s_line	*next;
}	t_line;

#endif
