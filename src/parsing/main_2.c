/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:02:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:52:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_extract_info_file(t_charlist *file, t_map *map)
{
	t_charlist	*line;
	t_charlist	*links;
	t_nodelist  *listnodes;

	listnodes = NULL;	
	line = file;
	ft_printf("/ **************** nbr ants ******************* \\ \n");
	if ((map->nbr_ants = ft_get_nbr_ants(line)) < 0)
		ft_ants_error(map->nbr_ants);
	ft_printf("/ **************** get rooms ****************** \\ \n");
	links = ft_get_room_graph(map, line->next, &listnodes);
	ft_printf("/ **************** get links ****************** \\ \n");
	ft_get_links_room_graph(links, listnodes);
	ft_printf("/ *************** end reading ***************** \\ \n");
	ft_put_list_nodelist(listnodes);
	ft_clear_list_nodelist(&listnodes);
}

void	read_map()
{
	t_charlist *file;
	t_map map;

	ft_init_map(&map);
	file = ft_first_passe();
	ft_extract_info_file(file, &map);
	ft_printf("/ **************** put file  ****************** \\ \n");
//	ft_put_list_charlist(file);
	ft_dell_list_charlist(&file);
	ft_put_map(&map);
}

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	read_map();
	return (0);
}
