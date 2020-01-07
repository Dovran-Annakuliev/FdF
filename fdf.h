/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:14:04 by rfork             #+#    #+#             */
/*   Updated: 2020/01/07 18:10:45 by rfork            ###   ########.fr       */
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

# include "libft/libft.h"
# include "sources/minilibx_macos/mlx.h"
# include "get_next_line.h"
# include "errors.h"

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
}				t_point;

t_mlx			*start();

void			suicide(char *error_text);

int main(void);
void grafon();

#endif
