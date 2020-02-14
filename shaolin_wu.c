/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shaolin_Wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:26 by rfork             #+#    #+#             */
/*   Updated: 2020/02/14 16:18:03 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shaolin_wu(t_mlx *data, int prjc)
{
	int k;
	int i;
	int j;

	k = ((IH / 2) - (data->map.heg / 2)) * IW + ((IH / 2) - (data->map.len / 2));
	i = 0;
	if (prjc)
	{
		i = -1;
		while (++i < data->map.heg)
		{
			j = -1;
			while (++j < data->map.len)
				data->img.img_data[k] = 0xbebebe;
			k = k + IW - data->map.len;
		}
	}
}
