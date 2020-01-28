/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:04:08 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 17:38:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*start(int argc, char **argv)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_error(0);
	if (!(data->mlx = mlx_init()))
		ft_error(0);
	if (!(data->window = mlx_new_window(data->mlx, H, W, "rule №34")))
		ft_error(0);
	if (!(data->img.mlx_img = mlx_new_image(data->mlx, iW, iH)))
		ft_error(0);
	if (!(data->img.mlx_addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bbp, &data->img.sz_l, &data->img.end)))
		ft_error(0);
	printf("data_addr = %s\n", data->img.mlx_addr);
	read_map(argc, argv, 0, data);
	return (data);
}
