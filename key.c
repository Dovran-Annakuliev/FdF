/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:50 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 19:46:39 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void 	def(t_mlx *data)
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
	if (key == z_p)
		data->cam.zoom_z++;
	if (key == z_m)
		data->cam.zoom_z--;
	draw_image(data);
}

static void		zoom(t_mlx *data, int key)
{
	if (key == zoom_p)
	{
		if (data->cam.zoom < 5.0f)
			data->cam.zoom = 5.0f;
		else
			data->cam.zoom += 5.0f;
	}
	if (key == zoom_m)
	{
		if (data->cam.zoom >= 10.0f)
			data->cam.zoom -= 5.0f;
		else if (data->cam.zoom >= 5.0f)
			data->cam.zoom = 2.0f;
	}
	draw_image(data);
}

static void 	close_fdf(t_mlx *data)
{
	free(data->arr);
	mlx_destroy_image(data->mlx, data->img.img_data);
	mlx_clear_window(data->mlx, data->window);
	(void)data;
	exit(0);
}

int 	deal_key(int key, t_mlx *data)
{
	if (key == x_dp_p || key == x_dp_m)
		shift_x(data, key);
	if (key == y_dp_p || key == y_dp_m)
		shift_y(data, key);
	if ((key == z_dp_p || key == z_dp_m) && data->map.prj == 1)
		shift_z(data, key);
	if (key == projection)
		project(data);
	if ((key == angl_x_p || key == angl_x_m) && data->map.prj == 1)
		rotate_x(data, key);
	if ((key == angl_y_p || key == angl_y_m) && data->map.prj == 1)
		rotate_y(data, key);
	if ((key == angl_z_p || key == angl_z_m) && data->map.prj == 1)
		rotate_z(data, key);
	if (key == default)
		def(data);
	if ((key == z_m || key == z_p) && data->map.prj == 1)
		change_z(data, key);
	if (key == zoom_m || key == zoom_p)
		zoom(data, key);
	if (key == esc)
		close_fdf(data);
	return (0);
}
