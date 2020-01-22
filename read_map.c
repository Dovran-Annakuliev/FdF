/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:16:25 by rfork             #+#    #+#             */
/*   Updated: 2020/01/22 19:15:14 by rfork            ###   ########.fr       */
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

void	split(t_point *data, char *map, int i)
{
	int j;
	char **arr;

	j = -1;
	arr = ft_strsplit(map, ' ');
	while (arr[++j])
	{
		data->x = j;
		data->y = i;
		data->z = ft_atoi(map);
		data->clr = ft_atoi_base(ft_strchr(map, ','));
	}
}

char **read_map(int argc, char **argv, int fd, int ret)
{
	char *line;
	int heg;
	int len;
	t_point *data;
	int i;
	t_map *map;

//	line = (char*)malloc(sizeof(char) * 1);
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)))
		ft_error(1);
	while (get_next_line(fd, &line))
	{
		if (!len)
			len = ft_strlen_split(line[0], ' ');
		if (len != ft_strlen_split(line[0], ' '))
			ft_error(2);
		free(line[0]);
		heg++;
	}
	map->heg = heg;
	map->len = len;
	close(fd);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, line[0]))
		{
			split(data, line[0], ++i);
			free(line[0]);
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
