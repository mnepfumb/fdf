/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:57:07 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:25:19 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_map *map, char **argv, int err)
{
	if (err != 2)
	{
		map->scale_x = ft_atoi(argv[2]);
		map->scale_y = ft_atoi(argv[3]);
	}
	else
	{
		map->scale_x = 20;
		map->scale_y = 20;
	}
	map->ori_x = map->scale_x;
	map->ori_y = map->scale_y;
	map->points_num = map->lines * map->width;
}

int			main(int argc, char **argv)
{
	t_map	map;
	int		err;

	map = read_map(argv[1]);
	err = (ft_argcheck(argc, argv));
	init_map(&map, argv, err);
	ft_map(&map, &map.points);
	free_file(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "fdf");
	ft_init_map(&map);
	mlx_key_hook(map.win, key_hook, &map);
	ft_draw_instruct(map);
	mlx_loop(map.mlx);
}
