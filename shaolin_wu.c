/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/22 11:30:11 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(double *x, double *y, double z)
{
    double previous_x;
    double previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	shaolin_wu(t_mlx *data, t_point crd1, t_point crd2)
{
	double dx;
	double dy;
	int steps;
//	int ki;
//	int kj;

//	ki = (int)((IH / 2.0f) - ((data->map.heg * data->cam.zoom) / 2));
//	kj = (int)((IW / 2.0f) - ((data->map.len * data->cam.zoom) / 2));
//	crd1.x *= data->cam.zoom;
//	crd1.y *= data->cam.zoom;
//	crd2.x *= data->cam.zoom;
//	crd2.y *= data->cam.zoom;
	crd1.x = crd1.x * data->cam.zoom + data->cam.x_dplace;
	crd1.y = crd1.y * data->cam.zoom + data->cam.y_dplace;
	crd2.x = crd2.x * data->cam.zoom + data->cam.x_dplace;
	crd2.y = crd2.y * data->cam.zoom + data->cam.y_dplace;
	iso(&crd1.x, &crd1.y, crd1.z);
	iso(&crd2.x, &crd2.y, crd2.z);
//	crd1.x += data->cam.x_dplace;
//	crd1.y += data->cam.y_dplace;
//	crd2.x += data->cam.x_dplace;
//	crd2.y += data->cam.y_dplace;
//	crd1.x += kj;
//	crd1.y += ki;
//	crd2.x += kj;
//	crd2.y += ki;
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
			data->img.img_data[(int)crd1.y * IW +(int)crd1.x] = crd2.clr;
		crd1.x += dx;
		crd1.y += dy;
	}
}

//{
//	int k;
//	int i;
//	int j;
//
//	k = ((IH / 2) - (data->map.heg / 2)) * IW + ((IW / 2) - (data->map.len / 2));
//	i = 0;
//	if (projections)
//	{
//		i = -1;
//		while (++i < data->map.heg)
//		{
//			j = -1;
//			while (++j < data->map.len)
//			{
//				data->img.img_data[k] = 0xbebebe;
//				k++;
//			}
//			k = k + IW - data->map.len;
//		}
//	}
//}
