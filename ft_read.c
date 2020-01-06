/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:16:25 by rfork             #+#    #+#             */
/*   Updated: 2020/01/06 13:18:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char **ft_read(int argc, char **argv, int fd, int ret)
{
	int fd;
	char **map;
	int count;
	int i;

	fd = 0;
	map = (char**)malloc(sizeof(char*) * 1);
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0) && (read(fd, buf, 0)) < 0))
		ft_error(1);
	while (get_next_line(fd, map[0]))
	{
		free(map[0]);
		count++;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = (char**)malloc(sizeof(char*) * (count + 1));
	i = 0;
	while (get_next_line(fd, map[i]))
	i++;
	map[i] = "\0";
}

void    ft_error(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./FdF target_file\n", 26);
		exit(0);
	} else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
