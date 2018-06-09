/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:13:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/08 18:56:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/node.h"

t_node		*ft_new_node(int id, char *name, intmax_t x, intmax_t y)
{
	t_node *ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->id = id;
	ret->name = name;
	ret->x = x;
	ret->y = y;
	ret->stats = 0;
	ret->list_neighbors = NULL;
	return (ret);
}
