/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:50 by rfork             #+#    #+#             */
/*   Updated: 2020/02/24 21:04:52 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	draw_image(data);
}

static void		rot_y(t_mlx *data, int key)
{
	if (key == angl_y_p)
		data->cam.angle_y += 0.0174533;
	if (key == angl_y_m)
		data->cam.angle_y -= 0.0174533;
	draw_image(data);
}

static void		rot_z(t_mlx *data, int key)
{
	if (key == angl_z_p)
		data->cam.angle_z += 0.0174533;
	if (key == angl_z_m)
		data->cam.angle_z -= 0.0174533;
	draw_image(data);
}

static void 	def(t_mlx *data)
{
	data->cam.zoom = 10.0f;
	data->cam.zoom_z = 1.0f;
	data->cam.angle_x = 0.0f;
	data->cam.angle_y = 0.0f;
	data->cam.angle_z = 0.0f;
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
	(void)data;
	exit(0);
}

int 	deal_key(int key, t_mlx *data)
{
//	printf("key = %d\n", key);
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
