/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/24 18:59:04 by dovran           ###   ########.fr       */
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
//	double bri;
	int steps;
	int d_red;
	int d_green;
	int d_blue;
	int red;
	int green;
	int blue;


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
	if (data->map.prj == 1)
	{
		iso(&crd1.x, &crd1.y, crd1.z);
		iso(&crd2.x, &crd2.y, crd2.z);
	}
	crd1.x += data->cam.x_dplace;
	crd1.y += data->cam.y_dplace;
	crd2.x += data->cam.x_dplace;
	crd2.y += data->cam.y_dplace;
	dx = crd2.x - crd1.x;
	dy = crd2.y - crd1.y;
	if (fabs(dx) > fabs(dy))
		steps = (int)fabs(dx);
	else
		steps = (int)fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	red = crd1.clr >> 16 & 0xFF;
	green = crd1.clr >> 8 & 0xFF;
	blue = crd1.clr & 0xFF;
	if (crd1.clr != crd2.clr)
	{
		d_red = (((crd2.clr >> 16) & 0xFF) - ((crd1.clr >> 16) & 0xFF)) / steps;
		d_green = (((crd2.clr >> 8) & 0xFF) - ((crd1.clr >> 8) & 0xFF)) / steps;
		d_blue = ((crd2.clr & 0xFF) - (crd1.clr & 0xFF)) / steps;
	}
	else
	{
		d_red = 0;
		d_green = 0;
		d_blue = 0;
	}
//	if (dx > dy)
//	{
//		while ((int) (crd1.x - crd2.x) || (int) (crd1.y - crd2.y))
//		{
//			if ((bri = crd1.y) > 5.0f)
//			{
//				if (((int) crd1.x >= 0 && (int) crd1.x < IW) && ((int) crd1.y >= 0 && (int) crd1.y < IH))
//					data->img.img_data[(int) crd1.y * IW + (int) crd1.x] = (((red * (int)bri / 10) << 16) | ((green * (int)bri / 10) << 8) | (blue * (int)bri / 10));
//				if (((int) crd1.x >= 0 && (int) crd1.x < IW) && ((int) (crd1.y + 1) >= 0 && (int) (crd1.y + 1) < IH))
//					data->img.img_data[(int) (crd1.y + 1) * IW + (int) crd1.x] = (((red * (int)(10 - bri) / 10) << 16) | ((green * (int)(10 - bri) / 10) << 8) | (blue * (int)(10 - bri) / 10));
//				crd1.x += dx;
//				crd1.y += dy;
//				red += d_red;
//				green += d_green;
//				blue += d_blue;
//			}
//			else
//			{
//				if (((int) crd1.x >= 0 && (int) crd1.x < IW) && ((int) crd1.y >= 0 && (int) crd1.y < IH))
//					data->img.img_data[(int) crd1.y * IW + (int) crd1.x] = (((red * (int)(10 - bri) / 10) << 16) | ((green * (int)(10 - bri) / 10) << 8) | (blue * (int)(10 - bri) / 10));
//				if (((int) crd1.x >= 0 && (int) crd1.x < IW) && ((int) (crd1.y - 1) >= 0 && (int) (crd1.y - 1) < IH))
//					data->img.img_data[(int) (crd1.y - 1) * IW + (int) crd1.x] = (((red * (int)bri / 10) << 16) | ((green * (int)bri / 10) << 8) | (blue * (int)bri / 10));
//				crd1.x += dx;
//				crd1.y += dy;
//				red += d_red;
//				green += d_green;
//				blue += d_blue;
//			}
//		}
//	}
//	else
//	{
//		while ((int) (crd1.x - crd2.x) || (int) (crd1.y - crd2.y))
//		{
//			if (fabs(bri = (10 * crd1.x - (int)crd1.x) * 10) > 5.0f)
//			{
//				if (((int) crd1.x >= 0 && (int) crd1.x < IW) && ((int) crd1.y >= 0 && (int) crd1.y < IH))
//					data->img.img_data[(int) crd1.y * IW + (int) crd1.x] = (((red * (int)bri / 10) << 16) | ((green * (int)bri / 10) << 8) | (blue * (int)bri / 10));
//				if (((int) (crd1.x + 1) >= 0 && (int) (crd1.x + 1) < IW) && ((int) (crd1.y) >= 0 && (int) (crd1.y) < IH))
//					data->img.img_data[(int) (crd1.y) * IW + (int) crd1.x + 1] = (((red * (int)(10 - bri) / 10) << 16) | ((green * (int)(10 - bri) / 10) << 8) | (blue * (int)(10 - bri) / 10));
//				crd1.x += dx;
//				crd1.y += dy;
//				red += d_red;
//				green += d_green;
//				blue += d_blue;
//			}
//			else
//			{
//				if (((int) crd1.x >= 0 && (int) crd1.x < IW) && ((int) crd1.y >= 0 && (int) crd1.y < IH))
//					data->img.img_data[(int) crd1.y * IW + (int) crd1.x] = (((red * (int)(10 - bri) / 10) << 16) | ((green * (int)(10 - bri) / 10) << 8) | (blue * (int)(10 - bri) / 10));
//				if (((int) (crd1.x - 1) >= 0 && (int) (crd1.x - 1) < IW) && ((int) (crd1.y) >= 0 && (int) (crd1.y) < IH))
//					data->img.img_data[(int)crd1.y * IW + (int)crd1.x - 1] = (((red * (int)bri / 10) << 16) | ((green * (int)bri / 10) << 8) | (blue * (int)bri / 10));
//				crd1.x += dx;
//				crd1.y += dy;
//				red += d_red;
//				green += d_green;
//				blue += d_blue;
//			}
//		}
//	}
	while ((int)(crd1.x - crd2.x) || (int)(crd1.y - crd2.y))
	{
		if (((int)crd1.x >= 0 && (int)crd1.x < IW) && ((int)crd1.y >= 0 && (int)crd1.y < IH))
			data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = ((red << 16) | (green << 8) | blue);
		crd1.x += dx;
		crd1.y += dy;
		red += d_red;
		green += d_green;
		blue += d_blue;
	}
}


