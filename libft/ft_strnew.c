/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:10:12 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:11:08 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*arr;

	if ((size + 1) == 0)
		return (NULL);
	i = 0;
	arr = (char*)malloc(sizeof(char) * (size + 1));
	if (arr)
	{
		while (i <= size + 1)
		{
			arr[i] = '\0';
			i++;
		}
		return (arr);
	}
	else
		return (NULL);
}
