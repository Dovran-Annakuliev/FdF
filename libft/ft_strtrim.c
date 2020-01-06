/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:30:13 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check2(void)
{
	char *arr;

	arr = (char *)malloc(sizeof(char) * (1));
	if (arr)
	{
		arr[0] = '\0';
		return (arr);
	}
	else
		return (NULL);
}

static char	*ft_check1(char const *s, int start, int end)
{
	int		i;
	int		j;
	char	*arr;

	j = 0;
	i = start;
	arr = (char*)malloc(sizeof(char) * (end - start + 2));
	if (arr)
	{
		while (i < (end + 1))
		{
			arr[j] = s[i];
			j++;
			i++;
		}
		arr[j] = '\0';
		return (arr);
	}
	else
		return (NULL);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*arr;

	if (!s)
		return (NULL);
	i = -1;
	start = 0;
	end = 0;
	while (s[++i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		start++;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != ',' && s[i] != '\n' && s[i] != '\t')
			end = i;
		i++;
	}
	if (start > end)
		arr = ft_check2();
	else
		arr = ft_check1(s, start, end);
	return (arr);
}
