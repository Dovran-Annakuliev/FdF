/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/14 18:55:07 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shaolin_wu(t_mlx *data, int crd1, int crd2, int projections)
{
	float dx;
	float dy;
	float steps;
	int i;

	dx = data->arr[crd1].x - data->arr[crd2].x;
	dy = data->arr[crd1].y - data->arr[crd2].y;
	if (abs(dx) >= abs(dy))
		steps = dx;
	else
		steps = dy;
	dx = dx / steps;
	dy = dy / steps;
	while ()
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
