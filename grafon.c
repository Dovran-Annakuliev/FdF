/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:15:11 by rfork             #+#    #+#             */
/*   Updated: 2020/01/06 13:18:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void grafon()
{
	void *mlx_ptr;
	void *win_ptr;

	if (!(mlx_ptr = mlx_init()))
		ft_error(0);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "grafon");
	mlx_loop(mlx_ptr);
}
