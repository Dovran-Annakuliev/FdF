/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:20:07 by rfork             #+#    #+#             */
/*   Updated: 2020/02/29 18:53:33 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;

	if (s1 && s2)
		arr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	else if (s1)
	{
		arr = ft_strdup(s1);
		return (arr);
	}
	else if (s2)
	{
		arr = ft_strdup(s2);
		return (arr);
	}
	if (s1 && s2)
	{
		arr = ft_strcpy(arr, s1);
		arr = ft_strcat(arr, s2);
		return (arr);
	}
	return (NULL);
}
