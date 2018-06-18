/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_antlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:27:52 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 20:49:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_put_antlist(const t_ant *list, t_nodelist *listnode)
{
	t_node	*node;

/*	if (ft_is_empty_antlist(list))
		ft_printf("[∅].\n");
	else
	{
		ft_printf("[");
		while (list)
		{
*/			node = ft_get_node_listnode(listnode, list->pos);
			ft_printf("%L{green}%ld{eoc}-{yellow}%s{eoc} ", list->id, node->name);
/*			list = list->next;
			if (list)
				ft_printf(",");
			//free node;
		}
		ft_printf("].\n");
	}*/
}
