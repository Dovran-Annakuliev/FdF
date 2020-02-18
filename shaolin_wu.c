/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/18 15:07:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shaolin_wu(t_mlx *data, t_point crd1, t_point crd2)
{
	double dx;
	double dy;
	double steps;

	crd1.x *= data->zoom;
	crd1.y *= data->zoom;
	crd2.x *= data->zoom;
	crd2.y *= data->zoom;
	printf("x1 = %f|y1 = %f\tx2 = %f|y2 =  %f\n", crd1.x, crd1.y, crd2.x, crd2.y);
	dx = crd2.x - crd1.x;
	dy = crd2.y - crd1.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	printf("dx = %f\tdy = %f\tsteps = %f\n", dx, dy, steps);
	while ((int)(crd1.x - crd2.x) || (int)(crd1.y - crd2.y))
	{
		if (((int)crd1.x >= 0 && (int)crd1.x < IW) && ((int)crd1.y >= 0 && (int)crd1.y < IH))
			data->img.img_data[(int)(crd1.y * IW + crd1.x)] = crd2.clr;
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
