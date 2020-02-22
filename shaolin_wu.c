/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/22 16:20:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void rot_x(double *y, double *z, t_mlx *data)
{
	double n_y;
	double n_z;

	n_y = *y;
	n_z = *z;
	*y = n_y * cos(data->cam.angle_x) + n_z * sin(data->cam.angle_x);
	*z = -n_y * sin(data->cam.angle_x) + n_z * cos(data->cam.angle_x);
}

static void rot_y(double *x, double *z, t_mlx *data)
{
	double n_x;
	double n_z;

	n_x = *x;
	n_z = *z;
	*x = n_x * cos(data->cam.angle_y) + n_z * sin(data->cam.angle_y);
	*z = -n_x * sin(data->cam.angle_y) + n_z * cos(data->cam.angle_y);
}

static void rot_z(double *x, double *y, t_mlx *data)
{
	double n_x;
	double n_y;

	n_x = *x;
	n_y = *y;
	*x = n_x * cos(data->cam.angle_z) - n_y * sin(data->cam.angle_z);
	*y = n_x * sin(data->cam.angle_z) + n_y * cos(data->cam.angle_z);
}

static void iso(double *x, double *y, double z)
{
    double n_x;
    double n_y;

	n_x = *x;
	n_y = *y;
    *x = (n_x - n_y) * cos(0.523599);
    *y = (n_x + n_y) * sin(0.523599) - z;
}

void	shaolin_wu(t_mlx *data, t_point crd1, t_point crd2)
{
	double dx;
	double dy;
	int steps;
	int color;


	crd1.x *= data->cam.zoom;
	crd1.y *= data->cam.zoom;
	crd1.z *= data->cam.zoom_z;
	crd2.x *= data->cam.zoom;
	crd2.y *= data->cam.zoom;
	crd2.z *= data->cam.zoom_z;
	rot_x(&crd1.y, &crd1.z, data);
	rot_x(&crd2.y, &crd2.z, data);
	rot_y(&crd1.x, &crd1.z, data);
	rot_y(&crd2.x, &crd2.z, data);
	rot_z(&crd1.x, &crd1.y, data);
	rot_z(&crd2.x, &crd2.y, data);
	iso(&crd1.x, &crd1.y, crd1.z);
	iso(&crd2.x, &crd2.y, crd2.z);
	crd1.x += data->cam.x_dplace;
	crd1.y += data->cam.y_dplace;
	crd2.x += data->cam.x_dplace;
	crd2.y += data->cam.y_dplace;
	color = (crd1.z > crd2.z) ? crd1.clr : crd2.clr;
	dx = crd2.x - crd1.x;
	dy = crd2.y - crd1.y;
	if (fabs(dx) > fabs(dy))
		steps = (int)fabs(dx);
	else
		steps = (int)fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	while ((int)(crd1.x - crd2.x) || (int)(crd1.y - crd2.y))
	{
		if (((int)crd1.x >= 0 && (int)crd1.x < IW) && ((int)crd1.y >= 0 && (int)crd1.y < IH))
			data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = color;
		crd1.x += dx;
		crd1.y += dy;
	}
}

