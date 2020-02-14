/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:14:04 by rfork             #+#    #+#             */
/*   Updated: 2020/02/14 14:32:06 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "libft/libft.h"
# include "sources/minilibx_macos/mlx.h"

# define W 2560
# define H 1600
# define iW 50//2560
# define iH 50//1600

typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
	int 		clr;
}				t_point;

typedef struct	s_map
{
	int			heg;
	int			len;
}				t_map;

typedef struct	s_image
{
	void		*image;
	int			*img_data;
	int			bbp;
	int			sz_l;
	int 		end;
}				t_image;

//t_color     int_to_rgb(int rgb)
//{
//	t_color col;
//	col = fill_color(0, 0, 0);
//	if (rgb == -1)
//		return (g_color(col, 0));
//	col.br = 1;
//	col.b = rgb & 255;
//	col.g = (rgb >> 8) & 255;
//	col.r = (rgb >> 16) & 255;
//	return (col);
//}

typedef struct	s_mlx
{
	void		*window;
	void		*mlx;
	t_point 	*arr;
	t_map 		map;
	t_image		img;
}				t_mlx;

t_mlx			*start(int argc, char **argv);
int				main(int argc, char **argv);
void			read_map(int argc, char **argv, int fd, t_mlx *data);
void			errors(int err);
//void			create_background(t_mlx *data);
int				deal_key(int key, t_mlx *data);
int				ft_atoi_base(const char *str);

#endif
