/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:36:45 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:22:25 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			colourpicker(t_point p1, t_point p2)
{
	long int	col;

	if (p1.col == 1 && p2.col == 1)
		col = WHITE;
	else if (p1.col == 1 || p2.col == 1)
	{
		if (p2.z < p1.z)
			col = BROWN;
		else
			col = BROWN;
	}
	else
		col = GREEN;
	return (col);
}

static void	draw_point(t_point p1, t_point p2, t_map *m, t_lines lpoints)
{
	long int	colour;
	float		step;

	step = (float)pow((fmax(fabs((double)(p1.x - p2.x)),
					fabs((double)(p1.z - p2.z)))), -1);
	while (!(p1.x == p2.x && p1.z == p2.z))
	{
		lpoints.e2 = lpoints.err;
		if (lpoints.e2 > -lpoints.dx)
		{
			lpoints.err -= lpoints.dy;
			p1.x += lpoints.sx;
		}
		if (lpoints.e2 < lpoints.dy)
		{
			lpoints.err += lpoints.dx;
			p1.z += lpoints.sy;
		}
		colour = colourpicker(p1, p2);
		mlx_pixel_put(m->mlx, m->win, p1.x, p1.z, colour);
	}
}

long int	ft_labs(long int k)
{
	if (k >= 0)
		return (k);
	return (-k);
}

void		draw_line(t_point p1, t_point p2, t_map *m)
{
	t_lines	lpoints;

	lpoints.dx = ft_labs(p2.x - p1.x);
	lpoints.sx = p1.x < p2.x ? 1 : -1;
	lpoints.dy = ft_labs(p2.z - p1.z);
	lpoints.sy = p1.z < p2.z ? 1 : -1;
	lpoints.err = (lpoints.dx > lpoints.dy ? lpoints.dx : -lpoints.dy) / 2;
	mlx_pixel_put(m->mlx, m->win, p1.x, p1.z, WHITE);
	draw_point(p1, p2, m, lpoints);
}
