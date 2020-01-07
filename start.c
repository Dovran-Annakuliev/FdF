/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:04:08 by rfork             #+#    #+#             */
/*   Updated: 2020/01/07 18:09:55 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*start()
{
	t_mlx *data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		suicide(ERR_MALLOC);
	if (!(data->mlx_ptr = mlx_init()))
		suicide(ERR_START_INIT);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, 640, 480, "Cake is a lie")))
		suicide(ERR_START_WIN);
	return (data);
}
