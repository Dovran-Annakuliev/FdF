/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:05:17 by rfork             #+#    #+#             */
/*   Updated: 2020/01/25 11:12:40 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void		*ft_free_split(char **arr, size_t k)
//{
//	size_t i;
//
//	i = 0;
//	while (i < k)
//		ft_strdel(&arr[i++]);
//	free(arr);
//	arr = NULL;
//	return (NULL);
//}
//
//static int		ft_strlen_split1(char const *s, char c)
//{
//	int i;
//	int len1;
//
//	i = 0;
//	len1 = 0;
//	while (s[i] != '\0')
//	{
//		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
//			len1++;
//		i++;
//	}
//	return (len1);
//}
//
//static size_t	ft_strlen_split2(const char *s, char c, size_t i)
//{
//	size_t k;
//
//	k = i;
//	while (s[k] && s[k] != c)
//		k++;
//	return (k - i);
//}
//
//char			**ft_strsplit(char const *s, char c)
//{
//	size_t	i;
//	size_t	k;
//	size_t	l;
//	char	**arr;
//
//	i = 0;
//	if (!s)
//		return (NULL);
//	k = ft_strlen_split1(s, c);
//	if (!(arr = (char**)malloc(sizeof(char*) * (k + 1))))
//		return (NULL);
//	k = 0;
//	while (s[i])
//	{
//		if (s[i] != c)
//		{
//			l = ft_strlen_split2(s, c, i);
//			if (!(arr[k++] = ft_strsub(s, i, l)))
//				return (ft_free_split(arr, k - 1));
//			i = i + l - 1;
//		}
//		i++;
//	}
//	arr[k] = NULL;
//	return (arr);
//}

int		ft_count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			words++;
		}
	}
	return (words);
}

static size_t	word_len(char const *s, char c, size_t i)
{
	size_t j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	return (j - i);
}

static void		*ft_strfree(char **s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		ft_strdel(&s[i++]);
	free(s);
	s = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_len(s, c, i);
			if (!(arr[j++] = ft_strsub(s, i, len)))
				return (ft_strfree(arr, j - 1));
			i = i + len - 1;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
