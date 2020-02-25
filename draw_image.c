/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:45:35 by rfork             #+#    #+#             */
/*   Updated: 2020/02/25 20:50:29 by dovran           ###   ########.fr       */
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

	data->cam.y_dplace = (int)((IH / 2.0f));// - ((data->map.heg * data->cam.zoom) / 2.0f));
	data->cam.x_dplace = (int)((IW / 2.0f));// - ((data->map.len * data->cam.zoom) / 2.0f));
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
//	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->img.image, 0, 0);
	mlx_string_put(data->mlx, data->window, 100, 50, 0xbebebe, "Exit - 'esc'");
	mlx_string_put(data->mlx, data->window, 100, 75, 0xbebebe, "Default - 'num_0'");
	mlx_string_put(data->mlx, data->window, 100, 100, 0xbebebe, "Projection - 'num_del'");
	mlx_string_put(data->mlx, data->window, 100, 125, 0xbebebe, "Change Z - 'num_*' 'num_/'");
	mlx_string_put(data->mlx, data->window, 100, 150, 0xbebebe, "Change scale - 'num_+' 'num_-'");
	mlx_string_put(data->mlx, data->window, 100, 175, 0xbebebe, "Rotation_x - 'num_4' 'num_6'");
	mlx_string_put(data->mlx, data->window, 100, 200, 0xbebebe, "Rotation_y - 'num_8' 'num_5");
	mlx_string_put(data->mlx, data->window, 100, 225, 0xbebebe, "Rotation_z - 'num_7' 'num_9'");
	mlx_string_put(data->mlx, data->window, 100, 250, 0xbebebe, "Move_x - 'left' 'right'");
	mlx_string_put(data->mlx, data->window, 100, 275, 0xbebebe, "Move_y - 'up' 'down'");
	mlx_string_put(data->mlx, data->window, 100, 300, 0xbebebe, "Move_z - 'num_1' 'num_3'");
}
