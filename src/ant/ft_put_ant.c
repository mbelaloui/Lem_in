/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:12:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:14:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_put_ant(const t_ant *list, t_nodelist *listnode)
{
	t_node	*node;

	node = ft_get_node_listnode(listnode, list->pos);
	ft_printf("%L{green}%ld{eoc}-{yellow}%s{eoc} ", list->id, node->name);
}
