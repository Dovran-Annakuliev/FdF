/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:04:08 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 16:56:15 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*start(int argc, char **argv, t_mlx *data)
{
	if (!(data->map = (t_map *)malloc(sizeof(t_map))))
		ft_error(0);
	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_error(0);
	if (!(data->mlx_ptr = mlx_init()))
		ft_error(0);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, 640, 480, "rule №34")))
		ft_error(0);
	read_map(argc, argv, 0, data);
	return (data);
}
