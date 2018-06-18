/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:35:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 21:13:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_put_best_path(t_int_list *path, t_nodelist *listnode)
{
	ft_printf("--------***** the best path ****--------\n");
	while (path)
	{
		ft_put_node(ft_get_node_listnode(listnode, path->data));
		path = path->next;
	}
}
void	ft_set_taken_room(int id_room, t_nodelist *listants)
{
	while (listants)
	{
		if (listants->node->id == id_room)
		{
			listants->node->stats = TAKEN;
			break;
		}
		listants = listants->next;
	}
}

BOOL	ft_is_next_step_free(int pos, t_int_list *path, t_nodelist *listnode,
		int id_end)
{
	int		id_next_room;
	t_node	*node;

	if (id_end == pos)
		return (-1);
	while (path && path->data != pos)
		path = path->next;
	if (!path)
		return (-1);
	path = path->next;
	node = ft_get_node_listnode(listnode, path->data);
	id_next_room = node->id;
	if (node->stats == FREE)
	{
		return (id_next_room);
	}
	return (-1);
}

void	ft_set_room_free(t_nodelist *listnode, int id)
{
	while (listnode)
	{
		if (listnode->node->id == id)
		{
			listnode->node->stats = FREE;
			break;
		}
		listnode = listnode->next;
	}
}

void	send_ant(t_ant *ants, t_int_list *path, t_nodelist *listnode, t_map map)
{
	int		id_next_room;
	t_ant *save_ant;
	int pos;

	ft_reste_status_listnode(listnode);
	save_ant = ants;

	int nbr = 0;
	while (nbr < map.nbr_ants)
	{
		ants = save_ant;
		while (ants)
		{
			pos = ants->pos;
			if ((id_next_room =ft_is_next_step_free(pos, path, listnode, map.end)) > -1)
			{
				if (ants->pos != 0)
					ft_set_room_free(listnode, ants->pos);
				ants->pos = id_next_room;
				if (id_next_room != map.end)
					ft_set_taken_room(id_next_room, listnode);
				ft_put_antlist(ants, listnode); // changer en put_ant 
				if (ants->pos == map.end)
					nbr++;
			}
			ants = ants->next;
		}
		ft_printf("\n");
	}
}

static void	run(t_map map, t_nodelist *listnode, t_int_list *path, t_option op)
{
	t_ant		*listants;

	listants = NULL;
	if (op.b)
		ft_put_best_path(path, listnode);
	listants = ft_init_ants(map.nbr_ants, map.start);
	ft_printf("\n");

	send_ant(listants, path, listnode, map);

	ft_dell_list_antlist(&listants);
	ft_clear_intlist(&path);
}

void	ft_resolve_map(t_map map, t_nodelist *listnode, t_option op)
{
	t_int_list *path;
	t_node *start;

	path = NULL;
	if (map.nbr_ants < 1 || map.start < 0 || map.end < 0 || !listnode)
		ft_erro_map(ERROR_NO_ENOUGH_DATA);
	start = ft_get_node_listnode(listnode, map.start);
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
