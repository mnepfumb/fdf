/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:56:24 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 12:56:26 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_argcheck(int argc, char **argv)
{
	if (argc == 2)
		return (2);
	if (argc != 4)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		return (-1);
	}
	else
	{
		if ((ft_atoi(argv[2]) == 0) || (ft_atoi(argv[3]) == 0))
		{
			ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
			return (-1);
		}
	}
	return (0);
}
