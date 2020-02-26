/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:50 by rfork             #+#    #+#             */
/*   Updated: 2020/02/26 12:59:20 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		shift_x(t_mlx *data, int key)
{
	if (key == x_dp_p)
		data->cam.x_dp += 10;
	if (key == x_dp_m)
		data->cam.x_dp -= 10;
	draw_image(data);
}

static void		shift_y(t_mlx *data, int key)
{
	if (key == y_dp_p)
		data->cam.y_dp += 10;
	if (key == y_dp_m)
		data->cam.y_dp -= 10;
	draw_image(data);
}

static void		shift_z(t_mlx *data, int key)
{
	if (key == z_dp_p)
		data->cam.z_dp += 10;
	if (key == z_dp_m)
		data->cam.z_dp -= 10;
	draw_image(data);
}

static void		project(t_mlx *data)
{
	if (data->map.prj == 0)
		data->map.prj = 1;
	else
		data->map.prj = 0;
	draw_image(data);
}

static void		rot_x(t_mlx *data, int key)
{
	if (key == angl_x_p)
		data->cam.angle_x += 0.0174533;
	if (key == angl_x_m)
		data->cam.angle_x -= 0.0174533;
	if ((data->cam.angle_x / 360) > 6.283188)
		data->cam.angle_x -= 360;
	if ((data->cam.angle_x / 360) < -6.283188)
		data->cam.angle_x += 360;
	data->cam.sin_x = sin(data->cam.angle_x);
	data->cam.cos_x = cos(data->cam.angle_x);
	draw_image(data);
}

static void		rot_y(t_mlx *data, int key)
{
	if (key == angl_y_p)
		data->cam.angle_y += 0.0174533;
	if (key == angl_y_m)
		data->cam.angle_y -= 0.0174533;
	if ((data->cam.angle_y / 360) > 6.283188)
		data->cam.angle_y -= 360;
	if ((data->cam.angle_y / 360) < -6.283188)
		data->cam.angle_y += 360;
	data->cam.sin_y = sin(data->cam.angle_y);
	data->cam.cos_y = cos(data->cam.angle_y);
	draw_image(data);
}

static void		rot_z(t_mlx *data, int key)
{
	if (key == angl_z_p)
		data->cam.angle_z += 0.0174533;
	if (key == angl_z_m)
		data->cam.angle_z -= 0.0174533;
	if ((data->cam.angle_z / 360) > 6.283188)
		data->cam.angle_z -= 360;
	if ((data->cam.angle_z / 360) < -6.283188)
		data->cam.angle_z += 360;
	data->cam.sin_z = sin(data->cam.angle_z);
	data->cam.cos_z = cos(data->cam.angle_z);
	draw_image(data);
}

static void 	def(t_mlx *data)
{
	data->cam.zoom = 10.0f;
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
		data->cam.zoom += 5.0f;
	if (key == zoom_m)
	{
		if (data->cam.zoom >= 10.0f)
			data->cam.zoom -= 5.0f;
//		else
//			data->cam.zoom = 1.0f;
	}
//	mlx_destroy_image(data->mlx, data->img.image);
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
//	printf("key = %d\n", key);
	if (key == x_dp_p || key == x_dp_m)
		shift_x(data, key);
	if (key == y_dp_p || key == y_dp_m)
		shift_y(data, key);
	if ((key == z_dp_p || key == z_dp_m) && data->map.prj == 1)
		shift_z(data, key);
	if (key == projection)
		project(data);
	if ((key == angl_x_p || key == angl_x_m) && data->map.prj == 1)
		rot_x(data, key);
	if ((key == angl_y_p || key == angl_y_m) && data->map.prj == 1)
		rot_y(data, key);
	if ((key == angl_z_p || key == angl_z_m) && data->map.prj == 1)
		rot_z(data, key);
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
