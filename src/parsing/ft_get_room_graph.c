/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_room_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:43:45 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:44:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

/*
 * **voir pour tout les cas de break si j'ai des le	aks
 * */

t_charlist		*ft_get_room_graph(t_map *map, t_charlist*line,
		t_nodelist **lstnodes)
{
	t_nodelist      *listnodes;

	t_node *temp_node;
	int cp;
	listnodes = NULL;
	cp = 0;
	ft_put_list_nodelist(listnodes);
	while (line)
	{
		if (ft_is_start(line->data))
		{
			if ( ft_is_end((line->next)->data) ||
					!(temp_node = ft_get_room((line->next)->data, cp)))
				break; //exit(1);
			else
				map->start = cp;
			line = line->next;
		}
		else if (ft_is_end(line->data))
		{
			if ( ft_is_start((line->next)->data) ||
					!(temp_node = ft_get_room((line->next)->data, cp)))
				break; //exit(1);
			else
				map->end = cp;
			line = line->next;
		}else
		{
			if (!(temp_node = ft_get_room(line->data, cp)))
				break ;//exit(1);
		}
		if (ft_exist_node_nodelist(temp_node, listnodes))
		{//error_room(ERROR_NAME_				ROOM_EXISTS);
			ft_dell_node( &temp_node);
			break;
		}
		else
			ft_add_end_list_nodelist(temp_node, &listnodes);
		cp ++;
		line = line->next;
	}


	*lstnodes = listnodes;
	return (line);
}
