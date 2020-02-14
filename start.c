/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:04:08 by rfork             #+#    #+#             */
/*   Updated: 2020/02/14 14:32:06 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_background(t_mlx *data)
{
	int i;

	i = -1;
	while (++i < (iW * iH))
	{
		data->img.img_data[i] = 0xff0000;
		if (i < (iW * iH / 2))
			data->img.img_data[i] = (0xff0000 / 2);
	}
}

t_mlx	*start(int argc, char **argv)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		errors(0);
	if (!(data->mlx = mlx_init()))
		errors(0);
	if (!(data->window = mlx_new_window(data->mlx, H, W, "FdF")))
		errors(0);
	if (!(data->img.image = mlx_new_image(data->mlx, iW, iH)))
		errors(0);
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.image, &data->img.bbp, &data->img.sz_l, &data->img.end)))
		errors(0);
	create_background(data);
	//printf("data_addr = %s\n", data->img.img_data);
	read_map(argc, argv, 0, data);
	return (data);
}
