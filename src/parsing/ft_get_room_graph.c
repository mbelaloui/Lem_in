/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_room_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:43:45 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 18:14:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

/*
**voir pour tout les cas de break si j'ai des leaks
*/

static BOOL		start_end_cas(t_charlist **line, int cp, t_map *map,
		t_node **temp_node)
{
	if (ft_is_start((*line)->data))
	{
		if (ft_is_end(((*line)->next)->data) ||
				!(*temp_node = ft_get_room(((*line)->next)->data, cp)))
			return (F);
		else
			map->start = cp;
		*line = (*line)->next;
	}
	else if (ft_is_end((*line)->data))
	{
		if (ft_is_start(((*line)->next)->data) ||
			!(*temp_node = ft_get_room(((*line)->next)->data, cp)))
			return (F);
		else
			map->end = cp;
		*line = (*line)->next;
	}
	else if (!(*temp_node = ft_get_room((*line)->data, cp)))
		return (F);
	return (T);
}

static void		check_next(t_charlist *line)
{
	if (ft_is_start(line->data))
		ft_room_error(ERROR_NO_START_ROOM_DECLARED, "");
	if (ft_is_end(line->data))
		ft_room_error(ERROR_NO_END_ROOM_DECLARED, "");
}

t_charlist		*ft_get_room_graph(t_map *map, t_charlist *line,
		t_nodelist **lstnodes)
{
	t_nodelist	*listnodes;
	t_node		*temp_node;
	int			cp;

	listnodes = NULL;
	cp = 0;
	while (line)
	{
		if (!start_end_cas(&line, cp++, map, &temp_node))
			break ;
		if (ft_exist_node_nodelist(temp_node, listnodes)
				&& ft_dell_node(&temp_node))
			break ;
		else
			ft_add_end_list_nodelist(temp_node, &listnodes);
		line = line->next;
	}
	if (line && (ft_is_start(line->data) || ft_is_end(line->data)))
		check_next(line);
	*lstnodes = listnodes;
	return (line);
}
