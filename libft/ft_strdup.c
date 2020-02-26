/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:30:43 by rfork             #+#    #+#             */
/*   Updated: 2020/01/25 11:12:40 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*ft_strdup(const char *src)
//{
//	int		i;
//	int		len;
//	char	*des;
//
//	len = ft_strlen(src);
//	des = (char*)malloc(sizeof(char) * len + 1);
//	i = 0;
//	if (des)
//	{
//		while (src[i] != '\0')
//		{
//			des[i] = src[i];
//			i++;
//		}
//		des[i] = '\0';
//		return (des);
//	}
//	else
//		return (NULL);
//}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*dup;

	i = 0;
	size = ft_strlen(s1);
	if ((dup = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			dup[i] = s1[i];
			i++;
		}
	}
	else
		return (NULL);
	dup[size] = '\0';
	return (dup);
}
