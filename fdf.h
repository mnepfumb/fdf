/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:56:39 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:50:22 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libc.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 600
# define DEFAULT_SCALE 20
# define ANGLE 5

# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BROWN 0xAD4F09

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define INFO01 "W and S for y rotation"
# define INFO02 "A and D for x rotation"
# define INFO03 "Q and E for z rotation"
# define INFO04 "Arrows for scale. R to reset"
# define INFO05 "I displays these instructions"

typedef struct		s_point
{
	long int	x;
	long int	y;
	long int	z;
	long int	col;
}					t_point;

typedef struct		s_map
{
	char		**map;

	long int	lines;
	long int	width;

	long int	points_num;
	void		*mlx;
	void		*win;
	t_point		**points;
	long int	scale_x;
	long int	scale_y;
	float		rot_x;
	float		rot_y;
	float		rot_z;
	long int	ori_x;
	long int	ori_y;
}					t_map;

typedef struct		s_lines
{
	long int	dx;
	long int	sx;
	long int	dy;
	long int	sy;
	long int	err;
	long int	e2;
}					t_lines;

t_point				new_point(long int x, long int y, long int z);
void				translate_point(long int x, long int y, long int
						z, t_map *map);
void				translate_rot(float angle, t_map *map,
						void (f)(float, t_map *));
void				scale_points(t_map *map, long int scale_x,
						long int scale_y);
void				rotate_x(float angle, t_map *map);
void				rotate_y(float angle, t_map *map);
void				rotate_z(float angle, t_map *map);
t_map				read_map(char *filename);
void				ft_map(t_map *map, t_point ***cloud);
void				ft_init_map(t_map *mapinfo);
int					ft_argcheck(int argc, char **argv);
void				draw_line(t_point v1, t_point v2, t_map *m);
void				ft_movemap(t_map *map, long int offset_x,
						long int offset_y);
void				centre_map(t_map *map);
void				ft_draw_map(t_map map);
void				ft_draw_instruct(t_map map);
int					key_hook(int keycode, t_map *map);
t_point				**ft_mapcopy(t_map *map);
void				free_map(t_map map);
void				free_file(t_map map);

#endif
