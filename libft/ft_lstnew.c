/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:21:56 by rfork             #+#    #+#             */
/*   Updated: 2019/09/23 15:29:25 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *point;

	if (!(point = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		point->content = NULL;
		point->content_size = 0;
	}
	else
	{
		if (!(point->content = (void*)malloc(sizeof(size_t) * content_size)))
		{
			free(point);
			return (NULL);
		}
		point->content = ft_memcpy(point->content, content, content_size);
		point->content_size = content_size;
	}
	point->next = NULL;
	return (point);
}
