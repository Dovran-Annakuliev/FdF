/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:10:44 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 20:25:28 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	if (!s)
		return (NULL);
	arr = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (arr)
	{
		while (i != len && s[i] != '\0')
		{
			arr[i] = s[start + i];
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	else
		return (NULL);
}
