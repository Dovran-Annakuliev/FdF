/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:30:43 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:12 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*des;

	len = ft_strlen(src);
	des = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	if (des)
	{
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
		return (des);
	}
	else
		return (NULL);
}
