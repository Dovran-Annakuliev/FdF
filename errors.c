/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:57:53 by rfork             #+#    #+#             */
/*   Updated: 2020/01/26 16:57:53 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    errors(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./FdF target_file\n", 26);
		exit(0);
	}
	else if (err == 2)
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

//
//int		ft_count_words(char const *s, char c)
//{
//	int	words;
//
//	words = 0;
//	while (*s)
//	{
//		while (*s == c)
//			s++;
//		if (*s)
//		{
//			while (*s && *s != c)
//				s++;
//			words++;
//		}
//	}
//	return (words);
//}
