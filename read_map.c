/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:48:57 by rfork             #+#    #+#             */
/*   Updated: 2020/02/22 16:03:02 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point(t_point p)
{
	printf("x = %f\ty = %f\tz = %f\tclr = %x\n", p.x, p.y, p.z, p.clr);
}


static int	ft_strlen_split(char const *s, char c)
{
//	int i;
//	int len;
//
//	i = -1;
//	len = 0;
//	while (s[++i] != '\0')
//		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
//			len++;
//	return (len);

	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			words++;
		}
	}
	return (words);
}

static void	split(t_mlx *data, char *line, int i)
{
	int		k;
	int		j;
	char	**array;

	j = -1;
	k = i * data->map.len;
	array = ft_strsplit(line, ' ');
	while (array[++j])
	{
		data->arr[k].x = j;
		data->arr[k].y = i;
		data->arr[k].z = (double)ft_atoi(array[j]);
//		printf("zb = %f\t", data->arr[k].z);
//		if (ft_strchr(array[j], ','))
//			data->arr[k].clr = ft_atoi_base(ft_strchr(array[j], ',') + 1);
//		else
//		{
//			if (data->arr[k].z == 0)
//				data->arr[k].clr = 0xbebebe;
//			else
//				data->arr[k].clr = 0xff00ff;
//		}
		if (ft_strchr(array[j], ','))
			data->arr[k].clr = ft_atoi_base(ft_strchr(array[j], ',') + 1);
//		else if (data->arr[k].z == 0)
//			data->arr[k].clr = 0xd2691e;
//		else if (data->arr[k].z > 0)
//			data->arr[k].clr = 0xbebebe;
//		else if (data->arr[k].z < 0)
//			data->arr[k].clr = 0x1e90ff;
		else if (data->arr[k].z == 0)
			data->arr[k].clr = 0xffffff;
		else if (data->arr[k].z > 0)
			data->arr[k].clr = 0xff0000;
		else if (data->arr[k].z < 0)
			data->arr[k].clr = 0x0000ff;
//		printf("za = %f\n", data->arr[k].z);
//		print_point(data->arr[k]);
		k++;
	}
}

static void	read_size(int fd, char *line, t_mlx *data)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		++i;
		if (!data->map.len)
		{
//			write(1, "a\n", 2);
			data->map.len = ft_strlen_split(line, ' ');
//			write(1, "b\n", 2);
		}
		if (data->map.len != ft_strlen_split(line, ' '))
			errors(2);
//		printf("i = %d\n", i);
//		write(1, "c\n", 2);
		ft_strdel(&line);
//		free(line);
//		write(1, "d\n", 2);
		data->map.heg++;
	}
}

void		read_map(int argc, char **argv, int fd, t_mlx *data)
{
	char	*line;
	int		i;

//	write(1, "1\n", 2);
	line = NULL;
	data->map.heg = 0;
	data->map.len = 0;
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)))
		errors(1);
//	write(1, "2\n", 2);
	read_size(fd, line, data);
//	write(1, "3\n", 2);
	ft_strdel(&line);
	data->arr = (t_point *)malloc(sizeof(t_point)
			* data->map.heg * data->map.len);
	close(fd);
//	write(1, "4\n", 2);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		split(data, line, ++i);
		ft_strdel(&line);
	}
//	write(1, "5\n", 2);
	ft_strdel(&line);
	close(fd);
}

