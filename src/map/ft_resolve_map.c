/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:35:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:22:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

static void	run(t_map map, t_nodelist *listnode, t_int_list *path, t_option op)
{
	t_ant		*listants;

	listants = NULL;
	if (op.b)
		ft_put_best_path(path, listnode, op);
	listants = ft_init_ants(map.nbr_ants, map.start);
	ft_printf("\n");
	ft_send_ants(listants, path, listnode, map);
	ft_dell_list_antlist(&listants);
	ft_clear_intlist(&path);
}

void		ft_resolve_map(t_map map, t_nodelist *listnode, t_option op)
{
	t_int_list	*path;
	t_node		*start;

	path = NULL;
	if (map.nbr_ants < 1 || map.start < 0 || map.end < 0 || !listnode)
		ft_erro_map(ERROR_NO_ENOUGH_DATA);
	start = ft_get_node_listnode(listnode, map.start);
	start->dist = 0;
	ft_add_end_intlist(map.start, &path);
	if (ft_find_path_width(listnode,
				start,
				ft_get_node_listnode(listnode, map.end),
				&path))
		run(map, listnode, ft_backtrack_path(listnode, map.end, map.start), op);
	else
	{
		ft_erro_map(ERROR_NO_PATH);
		exit(1);
	}
}
