/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/26 00:11:53 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void rot_x(double *y, double *z, t_mlx *data)
{
	double n_y;
//	double n_z;

	n_y = *y;
//	n_z = *z;
//	*y = n_y * cos(data->cam.angle_x) + n_z * sin(data->cam.angle_x);
//	*z = -n_y * sin(data->cam.angle_x) + n_z * cos(data->cam.angle_x);
	*y = n_y * data->cam.cos_x + *z * data->cam.sin_x;
	*z = -n_y * data->cam.sin_x + *z * data->cam.cos_x;
}

static void rot_y(double *x, double *z, t_mlx *data)
{
	double n_x;
//	double n_z;

	n_x = *x;
//	n_z = *z;
//	*x = n_x * cos(data->cam.angle_y) + n_z * sin(data->cam.angle_y);
//	*z = -n_x * sin(data->cam.angle_y) + n_z * cos(data->cam.angle_y);
	*x = n_x * data->cam.cos_y + *z * data->cam.sin_y;
	*z = -n_x * data->cam.sin_y + *z * data->cam.cos_y;
}

static void rot_z(double *x, double *y, t_mlx *data)
{
	double n_x;
//	double n_y;

	n_x = *x;
//	n_y = *y;
//	*x = n_x * cos(data->cam.angle_z) - n_y * sin(data->cam.angle_z);
//	*y = n_x * sin(data->cam.angle_z) + n_y * cos(data->cam.angle_z);
	*x = n_x * data->cam.cos_z - *y * data->cam.sin_z;
	*y = n_x * data->cam.sin_z + *y * data->cam.cos_z;
}

static void iso(double *x, double *y, double z)
{
    double n_x;
//    double n_y;

	n_x = *x;
//	n_y = *y;
    *x = (n_x - *y) * cos(0.523599);
    *y = (n_x + *y) * sin(0.523599) - z;
}

void	shaolin_wu(t_mlx *data, t_point crd1, t_point crd2)
{
	double dx;
	double dy;
//	double bri;
	double steps;
	int d_r;
	int d_g;
	int d_b;
	int r;
	int g;
	int b;
//	int color;


//	crd1.x += data->cam.x_dp;
//	crd1.y += data->cam.y_dp;
//	crd1.z += data->cam.z_dp;
//	crd2.x += data->cam.x_dp;
//	crd2.y += data->cam.y_dp;
//	crd2.z += data->cam.z_dp;

	crd1.x *= data->cam.zoom;
	crd1.y *= data->cam.zoom;
	crd1.z *= data->cam.zoom_z;
//	crd1.z += data->cam.z_dp;
	crd2.x *= data->cam.zoom;
	crd2.y *= data->cam.zoom;
	crd2.z *= data->cam.zoom_z;
//	crd2.z += data->cam.z_dp;

//	crd1.x += data->cam.x_dp;
//	crd1.y += data->cam.y_dp;
//	crd1.z += data->cam.z_dp;
//	crd2.x += data->cam.x_dp;
//	crd2.y += data->cam.y_dp;
//	crd2.z += data->cam.z_dp;

//	crd2.z += data->cam.z_dp;
//	crd1.x += data->cam.x_dp;
//	crd1.y += data->cam.y_dp;
//	crd2.x += data->cam.x_dp;
//	crd2.y += data->cam.y_dp;
	rot_x(&crd1.y, &crd1.z, data);
	rot_x(&crd2.y, &crd2.z, data);
	rot_y(&crd1.x, &crd1.z, data);
	rot_y(&crd2.x, &crd2.z, data);
	rot_z(&crd1.x, &crd1.y, data);
	rot_z(&crd2.x, &crd2.y, data);

	crd1.x += data->cam.x_dp;
	crd1.y += data->cam.y_dp;
	crd1.z += data->cam.z_dp;
	crd2.x += data->cam.x_dp;
	crd2.y += data->cam.y_dp;
	crd2.z += data->cam.z_dp;


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
		steps = (int) fabs(dx);
	else
		steps = (int) fabs(dy);
	r = crd1.clr >> 16 & 0xFF;
	g = crd1.clr >> 8 & 0xFF;
	b = crd1.clr & 0xFF;
	if (dx != 0 || dy != 0)
	{
		dx = dx / steps;
		dy = dy / steps;
//		color = (crd1.z > crd2.z) ? crd1.clr : crd2.clr;

		if (crd1.clr != crd2.clr)
		{
			d_r = (((crd2.clr >> 16) & 0xFF) - ((crd1.clr >> 16) & 0xFF)) / steps;
			d_g = (((crd2.clr >> 8) & 0xFF) - ((crd1.clr >> 8) & 0xFF)) / steps;
			d_b = ((crd2.clr & 0xFF) - (crd1.clr & 0xFF)) / steps;
		}
		else
		{
			d_r = 0;
			d_g = 0;
			d_b = 0;
		}
		while ((int)(crd1.x - crd2.x) || (int)(crd1.y - crd2.y))
		{
			if (((int)crd1.x >= 0 && (int)crd1.x < IW) && ((int)crd1.y >= 0 && (int)crd1.y < IH))
				data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = ((r << 16) | (g << 8) | b);
//				data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = color;
			crd1.x += dx;
			crd1.y += dy;
			r += d_r;
			g += d_g;
			b += d_b;
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


	}
	else
//		data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = color;
		data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = ((r << 16) | (g << 8) | b);
}


