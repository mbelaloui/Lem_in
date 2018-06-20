/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_info_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:12:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 15:55:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

t_nodelist		*ft_extract_info_file(t_charlist *file, t_map *map,
		t_charlist **links)
{
	t_charlist	*line;
	t_nodelist	*listnodes;

	*links = NULL;
	listnodes = NULL;
	line = file;
	if ((map->nbr_ants = ft_get_nbr_ants(line)) < 1)
		ft_ants_error(map->nbr_ants);
	*links = ft_get_room_graph(map, line->next, &listnodes);
	if (*links)
		ft_get_links_room_graph(*links, listnodes);
	return (listnodes);
}
