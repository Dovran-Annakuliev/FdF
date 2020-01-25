/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:03:09 by rfork             #+#    #+#             */
/*   Updated: 2020/01/25 11:12:40 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char*)malloc(sizeof(char) * size);
	if (arr)
	{
		while (i < size)
		{
			arr[i] = '\0';
			i++;
		}
		return (arr);
	}
	else
		return (NULL);
}
