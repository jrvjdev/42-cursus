/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:56:54 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 18:01:43 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	MAX_EVENT	32
#define MAX_PIXEL_NB	200000
#define UNIQ_BPP	4
#define FONT_WIDTH	10
#define	FONT_HEIGHT	20
typedef int (*func_t)();
typedef struct	s_glsl_info
{
  GLuint	pixel_vshader;
  GLuint	pixel_fshader;
  GLuint	pixel_program;
  GLint		loc_pixel_position;
  GLint		loc_pixel_texture;
  GLint		loc_pixel_winhalfsize;

  GLuint	image_vshader;
  GLuint	image_fshader;
  GLuint	image_program;
  GLint		loc_image_position;
  GLint		loc_image_winhalfsize;
  GLint		loc_image_texture;
  GLint		loc_image_pos;
  GLint		loc_image_size;

  GLuint	font_vshader;
  GLuint	font_fshader;
  GLuint	font_program;
  GLint		loc_font_position;
  GLint		loc_font_winhalfsize;
  GLint		loc_font_texture;
  GLint		loc_font_color;
  GLint		loc_font_posinwin;
  GLint		loc_font_posinatlas;
  GLint		loc_font_atlassize;
} t_glsl_info;


typedef struct	mlx_img_list_s
{
  int			width;
  int			height;
  char			*buffer;
  GLfloat		vertexes[8];
  struct mlx_img_list_s	*next;
} t_mlx_img_list;


typedef struct	mlx_img_ctx_s
{
  GLuint		texture;
  GLuint		vbuffer;
  t_mlx_img_list	*img;
  struct mlx_img_ctx_s	*next;
} mlx_img_ctx_t;

typedef struct	mlx_win_list_s
{
  void			*winid;
  mlx_img_ctx_t		*img_list;
  int			nb_flush;
  int			pixmgt;
  struct mlx_win_list_s	*next;
} t_mlx_win_list;


typedef struct		mlx_ptr_s
{
  void			*appid;
  t_mlx_win_list	*win_list;
  t_mlx_img_list	*img_list;
  void			(*loop_hook)(void *);
  void			*loop_hook_data;
  void			*loop_timer;
  t_mlx_img_list	*font;
  int			main_loop_active;
} mlx_ptr_t;

// proto

int	mlx_shaders(t_glsl_info *glsl);
char    **mlx_int_str_to_wordtab(char *str);
int     mlx_int_str_str(char *str,char *find,int len);
int     mlx_int_str_str_cote(char *str,char *find,int len);
int	mlx_destroy_image(mlx_ptr_t *mlx_ptr, t_mlx_img_list *img_ptr);
void	*mlx_new_image();
void    *mlx_xpm_to_image(mlx_ptr_t *xvar,char **xpm_data,int *width,int *height);
int	mlx_do_sync(mlx_ptr_t *mlx_ptr);
