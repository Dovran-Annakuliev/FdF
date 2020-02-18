/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:04:08 by rfork             #+#    #+#             */
/*   Updated: 2020/02/18 17:01:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data->zoom = 35.0f;
	return (data);
}
