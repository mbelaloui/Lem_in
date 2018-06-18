/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:32:54 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 18:31:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/lim_in.h"

int		ft_find_path_width(t_nodelist *listnodes, t_node *node,t_node *end,
		t_int_list **path)
{
	t_node *temp;
	t_int_list *list = node->list_neighbors;
	node->stats = 1;

	while (list)
	{
		temp = ft_get_node_listnode(listnodes, list->data);
		if (temp->stats == 0)
		{
			temp->dist  = node->dist + 1;
			ft_add_end_intlist(temp->id, path);
		}
		list = list->next;
		if (node->id == end->id)
		{
			ft_clear_intlist(path);
			return 1;
		}
	}
	ft_dell_bgn_int_list(path);
	//ft_put_int_list(*path);
	while (*path)
	{
		temp = ft_get_node_listnode(listnodes, (*path)->data);
		if (ft_find_path_width(listnodes, temp,end, path))
			return (1);
		else
			if (*path)
				*path = (*path)->next;
	}
	return (0);
}
