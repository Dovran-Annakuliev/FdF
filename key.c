/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:50 by rfork             #+#    #+#             */
/*   Updated: 2020/02/18 17:04:35 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom(t_mlx *data, int key)
{
	if (key == 24)
		data->zoom += 5.0f;
	if (key == 27)
	{
		if (data->zoom >= 10.0f)
			data->zoom -= 5.0f;
	}
//	mlx_destroy_image(data->mlx, data->img.image);
	draw_image(data);
}

static void 	close_fdf(t_mlx *data)
{
	(void)data;
	exit(0);
}

int 	deal_key(int key, t_mlx *data)
{
	if (key == 24 || key == 27)
		zoom(data, key);
	if (key == 53)
		close_fdf(data);
	return (0);
}
