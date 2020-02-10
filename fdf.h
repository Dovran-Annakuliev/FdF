/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:14:04 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 18:15:54 by rfork            ###   ########.fr       */
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
# define iW 3//2560
# define iH 3//1600

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
void			ft_error(int err);
//void			create_background(t_mlx *data);
int 	deal_key(int key, t_mlx *data);

#endif
