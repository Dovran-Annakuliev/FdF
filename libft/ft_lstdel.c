/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:47:04 by rfork             #+#    #+#             */
/*   Updated: 2019/09/19 16:39:57 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *point;
	t_list *tmp;

	if (!*alst && !del)
		return ;
	point = *alst;
	while (point)
	{
		tmp = point->next;
		ft_lstdelone(&point, del);
		point = tmp;
	}
	*alst = NULL;
}
