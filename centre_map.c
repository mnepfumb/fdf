/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centre_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:57:17 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 12:57:19 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centre_map(t_map *map)
{
	int	i;
	int	k;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = map->points[map->lines / 2][map->width / 2].x;
	offset_y = map->points[map->lines / 2][map->width / 2].z;
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x -= offset_x;
			map->points[i][k].x += WIDTH / 2;
			map->points[i][k].z -= offset_y;
			map->points[i][k].z += HEIGHT / 2;
			k++;
		}
		i++;
	}
}
