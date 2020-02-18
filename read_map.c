/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:48:57 by rfork             #+#    #+#             */
/*   Updated: 2020/02/18 17:34:23 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point(t_point p)
{
	printf("x = %f\ty = %f\tz = %f\tclr = %x\n", p.x, p.y, p.z, p.clr);
}


static int	ft_strlen_split(char const *s, char c)
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

static void	write_size(int fd, char *line, t_mlx *data)
{
	while (get_next_line(fd, &line))
	{
		if (!data->map.len)
			data->map.len = ft_strlen_split(line, ' ');
		if (data->map.len != ft_strlen_split(line, ' '))
			errors(2);
		ft_strdel(&line);
		data->map.heg++;
	}
}

void		read_map(int argc, char **argv, int fd, t_mlx *data)
{
	char	*line;
	int		i;

	line = NULL;
	data->map.heg = 0;
	data->map.len = 0;
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)))
		errors(1);
	write_size(fd, line, data);
	ft_strdel(&line);
	data->arr = (t_point *)malloc(sizeof(t_point)
			* data->map.heg * data->map.len);
	close(fd);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		split(data, line, ++i);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
}

/*
**printf("x = %d, y = %d, z = %d, clr = %x\n", data->arr[k].x,
** data->arr[k].y, data->arr[k].z, data->arr[k].clr);
*/
