/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:16:25 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 18:08:25 by rfork            ###   ########.fr       */
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

static void	split(t_mlx *data, char *map, int i)
{
	int k;
	int j;
	char **array;

	j = -1;
	k = 0;
	array = ft_strsplit(map, ' ');
	while (array[++j])
	{
		((data->arr) + k)->x = j;
		((data->arr) + k)->y = i;
		((data->arr) + k)->z = ft_atoi(array[j]);
		((data->arr) + k)->clr = ft_atoi_base(ft_strchr(array[j], ',') + 1);
		k++;
	}
}

void read_map(int argc, char **argv, int fd, t_mlx *data)
{
	char *line;
	int i;

	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)))
		ft_error(1);
	while (get_next_line(fd, &line))
	{
		if (!data->len)
			data->len = ft_strlen_split(line, ' ');
		if (data->len != ft_strlen_split(line, ' '))
			ft_error(2);
		free(line);
		data->heg++;
	}
	data->arr = (t_point *)malloc(sizeof(t_point) * data->heg * data->len);
	close(fd);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		{
			split(data, line, ++i);
			free(line);
		}
	close(fd);
}
