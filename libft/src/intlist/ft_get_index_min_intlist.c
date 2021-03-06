/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_min_intlist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:33:06 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:33:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

/*
**    input  ->    const list
**    output ->    index min in list
**    error  ->    if (is_empty (list))  ->  -1
**    interval of return ->  [0,   size_list - 1]
*/

int		ft_get_index_min_intlist(const t_int_list *list)
{
	int			index;
	int			index_min;
	intmax_t	min;

	if (!list)
		return (-1);
	min = list->data;
	index = 0;
	index_min = 0;
	while (list)
	{
		if (list->data < min)
		{
			index_min = index;
			min = list->data;
		}
		list = list->next;
		index++;
	}
	return (index_min);
}
