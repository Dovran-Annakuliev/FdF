/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:13:18 by rfork             #+#    #+#             */
/*   Updated: 2020/01/07 18:20:33 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_mlx *data)
{
	if (key != 51 && key != 53)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 320, 240, 16711680, ft_itoa(key));
	else if (key == 51)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	else if (key == 53)
		exit(0);
	return (0);
}

void	suicide(char *error_text)
{
	ft_putstr(error_text);
	exit(0);
}

int		main(void)
{
	t_mlx *data;

	data = start();
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

//int main(void)//int argc, char **argv)
//{
////	arr = read(argc, argv, 0, 0);
//	grafon();
//	return(0);
//}
