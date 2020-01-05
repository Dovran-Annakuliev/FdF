/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:13:18 by rfork             #+#    #+#             */
/*   Updated: 2020/01/05 17:24:54 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_error(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./FdF target_file\n", 26);
		exit(0);
	} else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

void govnokod_2_0()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "govnokod 2.0");
	mlx_loop(mlx_ptr);
}

char **read(int argc, char **argv, int fd, int ret)
{
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0) && (read(fd, buf, 0)) < 0))
		ft_error(1);
}

int main(int argc, char **argv)
{
	arr = read(argc, argv, 0, 0);
	govnokod_2_0();
	return(0);
}
