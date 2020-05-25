/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:01:18 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 23:25:17 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	shift_x(t_mlx *data, int key)
{
	if (key == X_DP_P)
		data->cam.x_dp += 10;
	if (key == X_DP_M)
		data->cam.x_dp -= 10;
	draw_image(data);
}

void	shift_y(t_mlx *data, int key)
{
	if (key == Y_DP_P)
		data->cam.y_dp += 10;
	if (key == Y_DP_M)
		data->cam.y_dp -= 10;
	draw_image(data);
}

void	shift_z(t_mlx *data, int key)
{
	if (key == Z_DP_P)
		data->cam.z_dp += 10;
	if (key == Z_DP_M)
		data->cam.z_dp -= 10;
	draw_image(data);
}
