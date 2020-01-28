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

void	create_background(t_mlx *data)
{
	int i;

	i = -1;
	while (++i < (iW * iH))
		data->img.img_data[i] = 0;
}

t_mlx	*start(int argc, char **argv)
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_error(0);
	if (!(data->mlx = mlx_init()))
		ft_error(0);
	if (!(data->window = mlx_new_window(data->mlx, H, W, "rule №34")))
		ft_error(0);
	if (!(data->img.image = mlx_new_image(data->mlx, iW, iH)))
		ft_error(0);
	if (!(data->img.img_data = mlx_get_data_addr(data->img.image, &data->img.bbp, &data->img.sz_l, &data->img.end)))
		ft_error(0);
	create_background(data);
	printf("data_addr = %s\n", data->img.img_data);
	read_map(argc, argv, 0, data);
	return (data);
}
