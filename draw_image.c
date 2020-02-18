/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:45:35 by rfork             #+#    #+#             */
/*   Updated: 2020/02/18 17:01:19 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_background(t_mlx *data)
{
	int i;

	i = -1;
	while (++i < (IW * IH))
		data->img.img_data[i] = 0x000000;
}

void draw_image(t_mlx *data)
{
	int i;
	int j;

//	if (!(data->img.image = mlx_new_image(data->mlx, IW, IH)))
//		errors(0);
//	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.image,&data->img.bbp, &data->img.sz_l, &data->img.end)))
//		errors(0);
	create_background(data);
	i = -1;
	while (++i < data->map.heg)
	{
		j = -1;
		while (++j < data->map.len)
		{
			if (j < data->map.len - 1)
				shaolin_wu(data, data->arr[i * data->map.len + j], data->arr[i * data->map.len + j + 1]);
			if (i < data->map.heg - 1)
				shaolin_wu(data, data->arr[i * data->map.len + j], data->arr[(i + 1) * data->map.len + j]);
		}
	}
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->img.image, 0, 0);
}
