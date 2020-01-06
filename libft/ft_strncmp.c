/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:07:45 by rfork             #+#    #+#             */
/*   Updated: 2019/09/18 16:06:13 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		f;

	i = 0;
	f = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (f == 0) && (i != n))
	{
		f = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if ((((s1[i] != '\0') && (s2[i] == '\0')) || ((s1[i] == '\0')
	&& (s2[i] != '\0'))) && f == 0 && i != n)
		f = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (f);
}
