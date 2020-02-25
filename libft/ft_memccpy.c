/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:46:16 by rfork             #+#    #+#             */
/*   Updated: 2020/02/22 19:26:51 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char    *s;
	unsigned char    *d;
	unsigned char    b;
	size_t            i;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == b)
			return (d + (i + 1));
		i++;
	}
	return (NULL);
}

//#include "libft.h"
//
//void	*ft_memccpy(void *dst, const void *src, int c,
//		size_t n)
//{
//	size_t i;
//
//	i = 0;
//	while (i < n)
//	{
//		((char*)dst)[i] = ((char*)src)[i];
//		if (((char*)src)[i] == (char)c)
//			return (&dst[i + 1]);
//		i++;
//	}
//	return (NULL);
//}
