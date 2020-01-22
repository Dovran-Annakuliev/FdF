/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:14:04 by rfork             #+#    #+#             */
/*   Updated: 2020/01/22 19:15:14 by rfork            ###   ########.fr       */
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
# include "errors.h"

typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
	int 		clr;
}				t_point;

typedef struct	s_map
{
	int			*heg;
	int			*len;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map 		map;
	t_point 	data;
}				t_mlx;

t_mlx			*start();

void			suicide(char *error_text);
int				main(int argc, char **argv);
void			grafon();
char			**read_map(int argc, char **argv, int fd, int ret);
void			ft_error(int err);
int				ft_atoi_base(const char *str);
void			split(t_point *data, char *map, int i);

#endif
