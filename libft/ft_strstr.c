/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:12:30 by rfork             #+#    #+#             */
/*   Updated: 2019/09/22 15:34:58 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	if (*to_find)
	{
		while (*str)
			if (!(ft_memcmp(str++, to_find, ft_strlen(to_find))))
				return ((char*)(str - 1));
		return (NULL);
	}
	return ((char*)str);
}
