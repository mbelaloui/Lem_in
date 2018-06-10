/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_links_room_graph.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:45:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:48:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_get_links_room_graph(t_charlist *links, t_nodelist *listnodes)
{
	char *name1;
	char *name2;

	while (links)
	{
		ft_printf(" %s \n", links->data);
		if (ft_is_c_in_str('-', links->data))		
		{

			if (ft_comptword(links->data, '-') != 2)
				ft_links_error(ERROR_FORMAT_LINK);

			name1  = ft_getword(links->data, 0, '-');
			name2  = ft_getword(links->data, 1, '-');
			
			/*ft_printf("%s   %s \t <%s>  l	en %d  %d  %d \n",name1, name2, links->data,
			//ft_strlen(name1),ft_st				rlen(name2),ft_strlen(links->data));
			*/
			if ((ft_strlen(name1) + ft_strlen(name2) + 1) != ft_strlen(links->data))
				ft_links_error(ERROR_FORMAT_LINK);



			if (!ft_is_name_in_nodelist(name1, listnodes))
				ft_links_error(ERROR_FORMAT_LINK_NAME);
			if (!ft_is_name_in_nodelist(name2, listnodes))
				ft_links_error(ERROR_FORMAT_LINK_NAME);

			ft_add_neighbors(listnodes, name1, name2);

			ft_strdel(&name1);
			ft_strdel(&name2);
		}
		else
			ft_links_error(ERROR_FORMAT_LINK);
		links = links->next;
	}
}
