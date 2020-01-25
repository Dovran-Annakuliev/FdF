/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:21:17 by rfork             #+#    #+#             */
/*   Updated: 2020/01/25 11:12:40 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		b;

	b = 0;
	i = 0;
	while (i < n)
	{
		if (src[i] != '\0' && b == 0)
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			b = 1;
		}
		i++;
	}
	return (dest);
}
