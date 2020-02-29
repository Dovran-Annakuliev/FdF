/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:11:49 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 20:16:59 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rot_x(double *y, double *z, t_mlx *data)
{
	double n_y;

	n_y = *y;
	*y = n_y * data->cam.cos_x + *z * data->cam.sin_x;
	*z = -n_y * data->cam.sin_x + *z * data->cam.cos_x;
}

static void	rot_y(double *x, double *z, t_mlx *data)
{
	double n_x;

	n_x = *x;
	*x = n_x * data->cam.cos_y + *z * data->cam.sin_y;
	*z = -n_x * data->cam.sin_y + *z * data->cam.cos_y;
}

static void	rot_z(double *x, double *y, t_mlx *data)
{
	double n_x;

	n_x = *x;
	*x = n_x * data->cam.cos_z - *y * data->cam.sin_z;
	*y = n_x * data->cam.sin_z + *y * data->cam.cos_z;
}

static void	iso(double *x, double *y, double z, t_mlx *data)
{
	double n_x;

	if (data->map.prj == 1)
	{
		n_x = *x;
		*x = (n_x - *y) * cos(0.523599);
		*y = (n_x + *y) * sin(0.523599) - z;
	}
}

void		shift(t_mlx *data, t_point *crd1, t_point *crd2)
{
	crd1->x *= data->cam.zoom;
	crd1->y *= data->cam.zoom;
	crd1->z *= data->cam.zoom_z;
	crd2->x *= data->cam.zoom;
	crd2->y *= data->cam.zoom;
	crd2->z *= data->cam.zoom_z;
	rot_x(&crd1->y, &crd1->z, data);
	rot_x(&crd2->y, &crd2->z, data);
	rot_y(&crd1->x, &crd1->z, data);
	rot_y(&crd2->x, &crd2->z, data);
	rot_z(&crd1->x, &crd1->y, data);
	rot_z(&crd2->x, &crd2->y, data);
	crd1->x += data->cam.x_dp;
	crd1->y += data->cam.y_dp;
	crd1->z += data->cam.z_dp;
	crd2->x += data->cam.x_dp;
	crd2->y += data->cam.y_dp;
	crd2->z += data->cam.z_dp;
	iso(&crd1->x, &crd1->y, crd1->z, data);
	iso(&crd2->x, &crd2->y, crd2->z, data);
	crd1->x += data->cam.x_dplace;
	crd1->y += data->cam.y_dplace;
	crd2->x += data->cam.x_dplace;
	crd2->y += data->cam.y_dplace;
}
