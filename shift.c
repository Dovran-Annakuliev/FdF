/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:01:18 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 20:10:54 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_x(t_mlx *data, int key)
{
	if (key == x_dp_p)
		data->cam.x_dp += 10;
	if (key == x_dp_m)
		data->cam.x_dp -= 10;
	draw_image(data);
}

void	shift_y(t_mlx *data, int key)
{
	if (key == y_dp_p)
		data->cam.y_dp += 10;
	if (key == y_dp_m)
		data->cam.y_dp -= 10;
	draw_image(data);
}

void	shift_z(t_mlx *data, int key)
{
	if (key == z_dp_p)
		data->cam.z_dp += 10;
	if (key == z_dp_m)
		data->cam.z_dp -= 10;
	draw_image(data);
}
