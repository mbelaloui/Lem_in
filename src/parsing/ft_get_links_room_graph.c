/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_links_room_graph.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:45:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/15 13:13:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

/*
**ft_printf("%s   %s \t <%s>  l	en %d  %d  %d \n",name1, name2, links->data,
**ft_strlen(name1),ft_st				rlen(name2),ft_strlen(links->data));
*/

static void		existe(char *name1, char *name2, t_nodelist *listnodes)
{
	if (!ft_strcmp(name1, name2))
		ft_links_error(ERROR_LINK_ROOM_ROOM, name1);
	if (!ft_is_name_in_nodelist(name1, listnodes))
		ft_links_error(ERROR_LINK_NAME_ROOM, name1);
	if (!ft_is_name_in_nodelist(name2, listnodes))
		ft_links_error(ERROR_LINK_NAME_ROOM, name2);
}

void			ft_get_links_room_graph(t_charlist *links,
		t_nodelist *listnodes)
{
	char *name1;
	char *name2;

	while (links && ft_is_c_in_str('-', links->data))
	{
		if (ft_comptword(links->data, '-') != 2)
			ft_links_error(ERROR_FORMAT_LINK, links->data);
		name1 = ft_getword(links->data, 0, '-');
		name2 = ft_getword(links->data, 1, '-');
		if ((ft_strlen(name1) +
			ft_strlen(name2) + 1) != ft_strlen(links->data))
			ft_links_error(ERROR_FORMAT_LINK, links->data);
		existe(name1, name2, listnodes);
		ft_add_neighbors(listnodes, name1, name2);
		ft_add_neighbors(listnodes, name2, name1);
		ft_strdel(&name1);
		ft_strdel(&name2);
		links = links->next;
	}
	if (links)
		ft_links_error(ERROR_FORMAT_LINK, links->data);
}
