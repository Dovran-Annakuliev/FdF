/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:04:08 by rfork             #+#    #+#             */
/*   Updated: 2020/02/22 16:17:26 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	displace(t_mlx *data)
{
	int i;
	int d_x;
	int d_y;

	i = -1;
	d_x = data->map.len / 2;
	d_y = data->map.heg / 2;
	while (++i < data->map.heg * data->map.len)
	{
		data->arr[i].x -= d_x;
		data->arr[i].y -= d_y;
	}
}

t_mlx	*start(int argc, char **argv)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		errors(0);
	if (!(data->mlx = mlx_init()))
		errors(0);
	if (!(data->window = mlx_new_window(data->mlx, W, H, "FdF")))
		errors(0);
	if (!(data->img.image = mlx_new_image(data->mlx, IW, IH)))
		errors(0);
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.image,&data->img.bbp, &data->img.sz_l, &data->img.end)))
		errors(0);
	read_map(argc, argv, 0, data);
	displace(data);
	data->cam.zoom = 10.0f;
	data->cam.zoom_z = 1.0f;
	data->cam.angle_x = 0.0f;
	data->cam.angle_y = 0.0f;
	data->cam.angle_z = 0.0f;
	return (data);
}
