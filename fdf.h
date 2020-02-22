/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:14:04 by rfork             #+#    #+#             */
/*   Updated: 2020/02/22 15:43:07 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "libft/libft.h"
#include "key.h"
#include "sources/minilibx_macos/mlx.h"

# define W 1920
# define H 1080
# define IW 1920
# define IH 1080

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			clr;
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
	int			end;
}				t_image;

typedef struct	s_cam
{
	double		zoom;
	double		x_dplace;
	double		y_dplace;
	double      x_m_dplc;
	double		y_m_dplc;
	double 		zoom_z;
	double 		angle_x;
	double 		angle_y;
	double 		angle_z;
}				t_cam;


typedef struct	s_mlx
{
	void		*window;
	void		*mlx;
	t_point		*arr;
	t_cam 		cam;
	t_map		map;
	t_image		img;
}				t_mlx;

t_mlx			*start(int argc, char **argv);
int				main(int argc, char **argv);
void			read_map(int argc, char **argv, int fd, t_mlx *data);
void			errors(int err);
int				deal_key(int key, t_mlx *data);
int				ft_atoi_base(const char *str);
void			shaolin_wu(t_mlx *data, t_point crd1, t_point crd2);
void			draw_image(t_mlx *data);



/*
 ** -------------------other----------------------
 */

void		print_point(t_point p);

#endif

