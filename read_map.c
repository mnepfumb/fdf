/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:57:48 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/12/07 15:28:46 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_lines(char *filename)
{
	int			fd;
	int			lines;
	char		*line;

	lines = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Error opening file.\n");
		exit(-1);
	}
	while (get_next_line(fd, &line))
	{
		lines++;
		free(line);
		line = NULL;
	}
	if (lines > 0)
		free(line);
	close(fd);
	return (lines);
}

t_map			read_map(char *filename)
{
	char		*line;
	t_map		file;
	int			fd;
	int			i;

	i = 0;
	file.lines = 0;
	file.map = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		return (file);
	file.lines = count_lines(filename);
	file.map = (char**)malloc(sizeof(char*) * file.lines);
	while (i < file.lines)
	{
		get_next_line(fd, &line);
		file.map[i++] = line;
	}
	close(fd);
	return (file);
}
