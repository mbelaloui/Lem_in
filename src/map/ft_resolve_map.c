/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:35:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/15 18:32:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

static void	erro_map(void)
{
	ft_printf("no enough data to find a path\n");
	exit(1);
}

int			ft_size_nodelist(t_nodelist *listnode)
{
	int ret;

	ret = 0;
	while (listnode)
	{
		ret++;
		listnode = listnode->next;
	}
	return (ret);
}

t_node		*ft_get_node_listnode(t_nodelist *listnode, int id)
{
	int pt;

	pt = 0;
	if (id < 0)
		return (NULL);
	while (listnode && pt < id)
	{
		listnode = listnode->next;
		pt++;
	}
	if(listnode)
		return(listnode->node);
	return(NULL);
}


void	ft_resolve_map(t_map map, t_nodelist *listnode)
{

	if (map.nbr_ants < 1 || map.start < 0 || map.end < 0 || !listnode)
		erro_map();
	int nbr_room;
	ft_printf("/ ********************* algorithme **************************** \\\n");

	ft_printf("size node list < room > %d \n", nbr_room = ft_size_nodelist(listnode));
	
/*	int cp = 0;
	while (cp < nbr_room)
	{
		ft_put_node(ft_get_node_listnode(listnode, cp));
		cp++;
	}*/


	t_int_list *list;

	list = NULL;
	t_node *node;
	ft_put_int_list(list);
	node = ft_get_node_listnode(listnode, map.start);
	ft_add_end_intlist(map.start, &list);
	ft_put_int_list(list);

	while (list)
	{

	}



}





































