/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:36:15 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 12:36:21 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_map(t_map *map)
{
	t_map	mapcpy;

	map->rot_x = 245;
	map->rot_y = 110;
	map->rot_z = -125;
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	scale_points(&mapcpy, map->scale_x, map->scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	centre_map(&mapcpy);
	ft_draw_map(mapcpy);
	free_map(mapcpy);
}

void		ft_draw_map(t_map map)
{
	long int	k;
	long int	l;

	k = 0;
	while (k < map.lines)
	{
		l = 0;
		while (l < map.width)
		{
			if (k + 1 < map.lines)
				draw_line(map.points[k][l], map.points[k + 1][l], &map);
			if (l + 1 < map.width)
				draw_line(map.points[k][l], map.points[k][l + 1], &map);
			l++;
		}
		k++;
	}
}

void		ft_draw_instruct(t_map map)
{
	mlx_string_put(map.mlx, map.win, 5, 5, WHITE, INFO01);
	mlx_string_put(map.mlx, map.win, 5, 20, WHITE, INFO02);
	mlx_string_put(map.mlx, map.win, 5, 35, WHITE, INFO03);
	mlx_string_put(map.mlx, map.win, 5, 50, WHITE, INFO04);
	mlx_string_put(map.mlx, map.win, 5, 65, WHITE, INFO05);
}
