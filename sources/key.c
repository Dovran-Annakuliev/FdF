/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:50 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 23:27:03 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		def(t_mlx *data)
{
	data->cam.zoom = 2.0f;
	data->cam.zoom_z = 1.0f;
	data->cam.angle_x = 0.0f;
	data->cam.angle_y = 0.0f;
	data->cam.angle_z = 0.0f;
	data->cam.sin_x = 0.0f;
	data->cam.cos_x = 1.0f;
	data->cam.sin_y = 0.0f;
	data->cam.cos_y = 1.0f;
	data->cam.sin_z = 0.0f;
	data->cam.cos_z = 1.0f;
	data->cam.x_dp = 0.0f;
	data->cam.y_dp = 0.0f;
	draw_image(data);
}

static void		change_z(t_mlx *data, int key)
{
	if (key == Z_P)
		data->cam.zoom_z++;
	if (key == Z_M)
		data->cam.zoom_z--;
	draw_image(data);
}

static void		zoom(t_mlx *data, int key)
{
	if (key == ZOOM_P)
	{
		if (data->cam.zoom < 5.0f)
			data->cam.zoom = 5.0f;
		else
			data->cam.zoom += 5.0f;
	}
	if (key == ZOOM_M)
	{
		if (data->cam.zoom >= 10.0f)
			data->cam.zoom -= 5.0f;
		else if (data->cam.zoom >= 5.0f)
			data->cam.zoom = 2.0f;
	}
	draw_image(data);
}

static void		close_fdf(t_mlx *data)
{
	free(data->arr);
	mlx_destroy_image(data->mlx, data->img.image);
	mlx_clear_window(data->mlx, data->window);
	(void)data;
	exit(0);
}

int				deal_key(int key, t_mlx *data)
{
	if (key == X_DP_P || key == X_DP_M)
		shift_x(data, key);
	if (key == Y_DP_P || key == Y_DP_M)
		shift_y(data, key);
	if ((key == Z_DP_P || key == Z_DP_M) && data->map.prj == 1)
		shift_z(data, key);
	if (key == PROJECTION)
		project(data);
	if ((key == ANGL_X_P || key == ANGL_X_M) && data->map.prj == 1)
		rotate_x(data, key);
	if ((key == ANGL_Y_P || key == ANGL_Y_M) && data->map.prj == 1)
		rotate_y(data, key);
	if ((key == ANGL_Z_P || key == ANGL_Z_M) && data->map.prj == 1)
		rotate_z(data, key);
	if (key == DEFAULT)
		def(data);
	if ((key == Z_M || key == Z_P) && data->map.prj == 1)
		change_z(data, key);
	if (key == ZOOM_M || key == ZOOM_P)
		zoom(data, key);
	if (key == ESC)
		close_fdf(data);
	return (0);
}
