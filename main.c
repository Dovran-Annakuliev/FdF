/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:13:18 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 17:38:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int		deal_key(int key, t_mlx *data)
//{
//	if (key != 51 && key != 53)
//		mlx_string_put(data->mlx, data->window, , 240, 16711680, ft_itoa(key));
//	else if (key == 51)
//		mlx_clear_window(data->mlx, data->window);
//	else if (key == 53)
//		exit(0);
//	return (0);
//}
//
//void	dda(t_mlx *data)
//{
//	t_point *p1;
//	t_point *p2;
//
//	p1 = (t_point *)malloc(sizeof(t_point));
//	p2 = (t_point *)malloc(sizeof(t_point));
//
//	p1->x = 0;
//	p1->y = 0;
//	p2->x = 320;
//	p2->y = 240;
//
//	double dx = p2->x - p1->x;
//	double dy = p2->y - p1->y;
//
//	double steps = fabs(dx) > fabs(dy) ? dx : dy;
//
//	double Xinc = dx / steps;
//	double Yinc = dy / steps;
//
//	double X = p1->x;
//	double Y = p1->y;
//	for (int i = 0; i <= steps; i++)
//	{
//		mlx_pixel_put(data->mlx, data->window, (int)round(X), (int)round(Y), 16711680);
//		X += Xinc;
//		Y += Yinc;
//	}
//}

int		main(int argc, char **argv)
{
	t_mlx *data;
	int i;

	i = 0;
	data = start(argc, argv);
	printf("map = %d\n", (data->map.heg * data->map.len));
	while (i < (data->map.heg * data->map.len))
	{

		printf("i = %d\nx = %d. y = %d, z = %d, clr = %d\n", i, data->arr[i].x, data->arr[i].y, data->arr[i].z, data->arr[i].clr);
		i++;
	}
//	mlx_key_hook(data->window, deal_key, data);
//	dda(data);
//
//	mlx_loop(data->mlx);
	return (0);
}

//int main(void)//int argc, char **argv)
//{
////	arr = read(argc, argv, 0, 0);
//	grafon();
//	return(0);
//}
