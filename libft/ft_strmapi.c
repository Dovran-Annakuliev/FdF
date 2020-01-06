/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:57:25 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (arr)
	{
		while (s[i] != '\0')
		{
			arr[i] = (*f)(i, s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	else
		return (NULL);
}
