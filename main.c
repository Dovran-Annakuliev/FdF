/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:13:18 by rfork             #+#    #+#             */
/*   Updated: 2020/02/18 17:06:16 by rfork            ###   ########.fr       */
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
	mlx_loop(data->mlx);
	return (0);
}
