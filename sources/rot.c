/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:51:45 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 23:22:56 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_mlx *data, int key)
{
	if (key == ANGL_X_P)
		data->cam.angle_x += 0.0174533;
	if (key == ANGL_X_M)
		data->cam.angle_x -= 0.0174533;
	if ((data->cam.angle_x / 360) > 6.283188)
		data->cam.angle_x -= 360;
	if ((data->cam.angle_x / 360) < -6.283188)
		data->cam.angle_x += 360;
	data->cam.sin_x = sin(data->cam.angle_x);
	data->cam.cos_x = cos(data->cam.angle_x);
	draw_image(data);
}

void	rotate_y(t_mlx *data, int key)
{
	if (key == ANGL_Y_P)
		data->cam.angle_y += 0.0174533;
	if (key == ANGL_Y_M)
		data->cam.angle_y -= 0.0174533;
	if ((data->cam.angle_y / 360) > 6.283188)
		data->cam.angle_y -= 360;
	if ((data->cam.angle_y / 360) < -6.283188)
		data->cam.angle_y += 360;
	data->cam.sin_y = sin(data->cam.angle_y);
	data->cam.cos_y = cos(data->cam.angle_y);
	draw_image(data);
}

void	rotate_z(t_mlx *data, int key)
{
	if (key == ANGL_Z_P)
		data->cam.angle_z += 0.0174533;
	if (key == ANGL_Z_M)
		data->cam.angle_z -= 0.0174533;
	if ((data->cam.angle_z / 360) > 6.283188)
		data->cam.angle_z -= 360;
	if ((data->cam.angle_z / 360) < -6.283188)
		data->cam.angle_z += 360;
	data->cam.sin_z = sin(data->cam.angle_z);
	data->cam.cos_z = cos(data->cam.angle_z);
	draw_image(data);
}

void	project(t_mlx *data)
{
	if (data->map.prj == 0)
		data->map.prj = 1;
	else
		data->map.prj = 0;
	draw_image(data);
}
