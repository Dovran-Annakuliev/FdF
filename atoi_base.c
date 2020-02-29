/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:30:35 by rfork             #+#    #+#             */
/*   Updated: 2020/02/25 19:15:49 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str)
{
	int str_base;
	int nb;
	int	i;

	nb = 0;
	i = 2;
	if (str[0] == '0' && str[1] == 'x')
	{
		str_base = 16;
		while (base(str[i], str_base) != -1)
		{
			nb = nb * str_base;
			nb = nb + base(str[i], str_base);
			i++;
		}
	}
	return (nb);
}
