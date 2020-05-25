/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 21:03:41 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	color(t_point crd1, t_point crd2, t_mlx *data)
{
	data->clr.r = crd1.clr >> 16 & 0xFF;
	data->clr.g = crd1.clr >> 8 & 0xFF;
	data->clr.b = crd1.clr & 0xFF;
	if (crd1.clr != crd2.clr)
	{
		data->clr.d_r = (((crd2.clr >> 16) & 0xFF) -
				((crd1.clr >> 16) & 0xFF)) / data->clr.st;
		data->clr.d_g = (((crd2.clr >> 8) & 0xFF) -
				((crd1.clr >> 8) & 0xFF)) / data->clr.st;
		data->clr.d_b = ((crd2.clr & 0xFF) -
				(crd1.clr & 0xFF)) / data->clr.st;
	}
	else
	{
		data->clr.d_r = 0;
		data->clr.d_g = 0;
		data->clr.d_b = 0;
	}
}

static void	increment(t_mlx *data)
{
	data->clr.r += data->clr.d_r;
	data->clr.g += data->clr.d_g;
	data->clr.b += data->clr.d_b;
}

void		brez(t_mlx *d, t_point c1, t_point c2)
{
	double	dx;
	double	dy;

	shift(d, &c1, &c2);
	dx = c2.x - c1.x;
	dy = c2.y - c1.y;
	d->clr.st = (fabs(dx) > fabs(dy)) ? (int)fabs(dx) : (int)fabs(dy);
	if (dx == 0 && dy == 0)
		d->img.img_data[(int)c1.y * IW + (int)c1.x] = c1.clr;
	else
	{
		dx = dx / d->clr.st;
		dy = dy / d->clr.st;
		color(c1, c2, d);
		while ((int)(c1.x - c2.x) || (int)(c1.y - c2.y))
		{
			if (((int)c1.x >= 0 && (int)c1.x < IW) && ((int)c1.y >= 0
				&& (int)c1.y < IH))
				d->img.img_data[(int)c1.y * IW + (int)c1.x] =
						((d->clr.r << 16) | (d->clr.g << 8) | d->clr.b);
			c1.x += dx;
			c1.y += dy;
			increment(d);
		}
	}
}
