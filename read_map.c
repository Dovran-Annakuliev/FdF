/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:16:25 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 18:15:54 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	base(int c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int  i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

static int ft_atoi_base(const char *str)
{
	int str_base;
	int nb = 0;
	int	i = 2;

	str_base = 16;
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	return (nb);
}

static int		ft_strlen_split(char const *s, char c)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (s[++i] != '\0')
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			len++;
	return (len);
}

static void	split(t_mlx *data, char *line, int i)
{
	int k;
	int j;
	char **array;
	char *test;

	j = -1;
	k = i * 10;
//	printf("line = %s\n", line);
	array = ft_strsplit(line, ' ');
//	printf("array[2][2] = %s\n", array[2][2]);
	while (array[++j])
	{
		printf("array = %s\nj = %d\n", array[j], j);
		data->arr[k].x = j;
		data->arr[k].y = i;
		data->arr[k].z = ft_atoi(array[j]);
		if (ft_strchr(array[j], ','))
			data->arr[k].color = ft_atoi_base(ft_strchr(array[j], ',') + 1);
		else
			data->arr[k].color = 12500670;
		printf("x = %d, y = %d, z = %d, color = %d\n", data->arr[k].x, data->arr[k].y, data->arr[k].z, data->arr[k].color); //!!!!!
		k++;
	}
}

void read_map(int argc, char **argv, int fd, t_mlx *data)
{
	char *line;
	int i;

	data->heg = 0;
	data->len = 0;
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)))
		ft_error(1);
	while (get_next_line(fd, &line))
	{
		if (!data->len)
			data->len = ft_strlen_split(line, ' ');
		if (data->len != ft_strlen_split(line, ' '))
			ft_error(2);
		ft_strdel(&line);
		data->heg++;
	}
//	printf("heg = %d, len = %d\n", data->heg, data->len);
//	printf("line = %s\n", line);
	ft_strdel(&line);
	data->arr = (t_point *)malloc(sizeof(t_point) * data->heg * data->len);
	close(fd);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		{
//			printf("line = %s\n", line);
			split(data, line, ++i);
			ft_strdel(&line);
//			free(line);
		}
	write(1, "wirte\n", 6);
	ft_strdel(&line);
//	free(line);
	close(fd);
}
