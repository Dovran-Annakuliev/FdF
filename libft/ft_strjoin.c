/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:20:07 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen1(char const *s1, char const *s2)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	len = i + j - 1;
	return (len);
}

char			*ft_while1(char const *s1, char const *s2, char *arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;

	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	if (s1[0] == '\0' && s2[0] == '\0')
	{
		arr = (char*)malloc(sizeof(char) * 1);
		arr[0] = '\0';
		return (arr);
	}
	arr = (char*)malloc(sizeof(char) * ft_strlen1(s1, s2));
	if (arr)
	{
		arr = ft_while1(s1, s2, arr);
		return (arr);
	}
	else
		return (NULL);
}
