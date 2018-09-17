/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:36:02 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:27:30 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_numbers(char *str)
{
	long int	k;
	long int	num;

	k = 0;
	num = 0;
	while (str[k] != '\0')
	{
		if (ft_isdigit(str[k]))
		{
			num++;
			while ((ft_isdigit(str[k]) && str[k])
					|| str[k] == ',' || str[k] == 'x')
				k++;
		}
		else
			k++;
	}
	return (num);
}

void			ft_map(t_map *map, t_point ***cloud)
{
	long int	z;
	long int	x;
	char		**split_line;
	t_point		**new;

	z = 0;
	map->width = count_numbers(map->map[z]);
	new = (t_point**)malloc(sizeof(t_point*) * map->lines);
	while (z < map->lines)
	{
		new[z] = (t_point*)malloc(sizeof(t_point) * map->width);
		x = 0;
		split_line = ft_strsplit(map->map[z], ' ');
		while (x < map->width)
		{
			new[z][x] = new_point(x, ft_atoi(split_line[x]), z);
			x++;
		}
		free(split_line);
		z++;
	}
	*cloud = new;
}

t_point			**ft_mapcopy(t_map *map)
{
	long int	k;
	long int	l;
	t_point		**new;

	k = 0;
	new = (t_point**)malloc(sizeof(t_point*) * map->lines);
	while (k < map->lines)
	{
		new[k] = (t_point*)malloc(sizeof(t_point) * map->width);
		l = 0;
		while (l < map->width)
		{
			new[k][l] = map->points[k][l];
			l++;
		}
		k++;
	}
	return (new);
}
