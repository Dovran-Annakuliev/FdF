/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:16:25 by rfork             #+#    #+#             */
/*   Updated: 2020/01/22 16:09:07 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_strlen_split(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			len++;
		i++;
	}
	return (len);
}

static char *po4ti_atoi()
{

}

void	split(t_point *data, char *map)
{
	int i;
	char **arr;

	i = -1;
	arr = ft_strsplit(map, ' ');
	while (arr[++i])
	{
		data->x = ft_atoi(map);
		data->y = ft_atoi(ft_strchr(map, ','));
		data->clr = ft_strchr(ft_strchr(map, ','), ',');
	}
}

char **ft_read(int argc, char **argv, int fd, int ret)
{
	char **map;
	int heg;
	int len;
	t_point *data;

	map = (char**)malloc(sizeof(char*) * 1);
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)))
		ft_error(1);
	while (get_next_line(fd, map[0]))
	{
		if (!len)
			len = ft_strlen_split(map[0], ' ');
		if (len != ft_strlen_split(map[0], ' '))
			ft_error(2);
		free(map[0]);
		heg++;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, map[0]))
		{
			split(data, map[0]);
			free(map[0]);
		}
	close(fd);
}

void    ft_error(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./FdF target_file\n", 26);
		exit(0);
	}
	else if (err == 2)
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
