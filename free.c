/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:58:30 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:23:52 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			free_file(t_map map)
{
	int			l;

	l = 0;
	while (l < map.lines)
	{
		free(map.map[l]);
		l++;
	}
	free(map.map);
}

void			free_map(t_map map)
{
	long int	k;

	k = -1;
	while (++k < map.lines)
		free(map.points[k]);
	free(map.points);
	map.points = NULL;
}
