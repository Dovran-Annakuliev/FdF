/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:13:18 by rfork             #+#    #+#             */
/*   Updated: 2020/02/25 17:07:44 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx *data;
//	int i;

//	i = -1;
	data = start(argc, argv);
//	for (int k = 0; k < (data->map.heg * data->map.len) ; ++k)
//		print_point(data->arr[k]);
	draw_image(data);
	mlx_hook(data->window, 2, 1l<<0, deal_key, data);
//	mlx_hook(data->window, 4, 1l<<0, mouse_key, data);
//	mlx_hook(data->window, 6, 1l<<0, mouse_move, data);
	mlx_loop(data->mlx);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_data);
	return (0);
}
