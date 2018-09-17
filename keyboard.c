/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:24:14 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:24:53 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rot(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		map->rot_y += ANGLE;
	if (keycode == KEY_S)
		map->rot_y -= ANGLE;
	if (keycode == KEY_A)
		map->rot_x += ANGLE;
	if (keycode == KEY_D)
		map->rot_x -= ANGLE;
	if (keycode == KEY_Q)
		map->rot_z += ANGLE;
	if (keycode == KEY_E)
		map->rot_z -= ANGLE;
}

static void	key_scale(int keycode, t_map *map)
{
	if (keycode == KEY_LEFT)
		map->scale_x -= 1;
	if (keycode == KEY_RIGHT)
		map->scale_x += 1;
	if (keycode == KEY_UP)
		map->scale_y += 1;
	if (keycode == KEY_DOWN)
		map->scale_y -= 1;
}

static void	key_reset(t_map *map)
{
	map->rot_x = 245;
	map->rot_y = 110;
	map->rot_z = -125;
	map->scale_x = map->ori_x;
	map->scale_y = map->ori_y;
}

int			key_hook(int keycode, t_map *map)
{
	t_map mapcpy;

	if (keycode == ESC)
		exit(0);
	else if (keycode == KEY_R)
		key_reset(map);
	else if (keycode >= KEY_A && keycode <= KEY_E)
		key_rot(keycode, map);
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		key_scale(keycode, map);
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	mlx_clear_window(0, map->win);
	scale_points(&mapcpy, mapcpy.scale_x, mapcpy.scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	centre_map(&mapcpy);
	ft_draw_map(mapcpy);
	free_map(mapcpy);
	if (keycode == 15 || keycode == 34)
		ft_draw_instruct(*map);
	return (0);
}
