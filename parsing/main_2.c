/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:02:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/09 11:52:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lim_in.h"

void    ft_put_map(t_map *map)
{
	ft_printf("nbr of ants %d \n", map->nbr_ants);
	ft_printf("id of starting room %d \n", map->start);
	ft_printf("id of ending room %d \n", map->end);
}

/*********************************************************************/
/*********************************************************************/

void    ft_init_map(t_map *map)
{
	map->nbr_ants = 0;
}

BOOL	is_start(char *str)
{
	char *start;

	start = "##start";
	if (!ft_strcmp(str, start))
		return (T);
	return (F);
}

BOOL	is_end(char *str)
{
	char *start;

	start = "##end";
	if (!ft_strcmp(str, start))
		return (T);
	return (F);
}

BOOL	is_comment(char *str)
{
	if (str)
	{	
		if (is_start(str) || is_end(str))
			return (F);
		if (str[0] == '#')
			return (T);
	}
	return (F);
}

void	error_syntax(int error)
{
	ft_printf(" error syntax id %d  ", error);

	exit(1);
}

/*
 ** first passe read the file and ignor the commants 
 **	
 **	if (empty line) 
 **						return (ERROR_EMPTY_LINE)
 **
 ** if (##start) found twice separate in the file or not found 
 **						return (ERROR_START_FORMAT)
 ** 
 ** if (##end) found twice separate in the file or not found 
 **						return (ERROR_END_FORMAT)
 **
 **	for not found may be make an other case of error.....
 **		
 ** return a linked list of line <char *>
 */

t_charlist	*first_passe()
{
	t_charlist *ret;
	char *line;
	char *temp;
	BOOL  s;
	BOOL  e;

	s = F;
	e = F;
	line = NULL;
	ret = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_strlen(line))
			error_syntax(ERROR_EMPTY_LINE);
		if (is_start(line))
		{
			if (s)
				error_syntax(ERROR_START_FORMAT);
			else
			{
				temp = ft_format_str(line);
				ft_add_charlist(temp, &ret);
				ft_strdel(&temp);
				ft_strdel(&line);
				while (get_next_line(0, &line) &&
						(is_start(line) || is_comment(line)))
					ft_strdel(&line);
			}
			s = T;
		}
		if (is_end(line))
		{
			if (e)
				error_syntax(ERROR_END_FORMAT);
			else
			{
				temp = ft_format_str(line);
				ft_add_charlist(temp, &ret);
				ft_strdel(&temp);
				ft_strdel(&line);
				while (get_next_line(0, &line) &&
						(is_end(line) || is_comment(line)))
					ft_strdel(&line);
			}
			e = T;
		}	
		if (!is_comment(line))
		{
			temp = ft_format_str(line);
			ft_add_charlist(temp, &ret);
			ft_strdel(&temp);
		}
		ft_strdel(&line);
	}

	if (!s)
		error_syntax(ERROR_NO_START);
	if (!e)
		error_syntax(ERROR_NO_END);

	
	if (!ret)
		error_syntax(ERROR_EMPTY_FILE);
	ft_strdel(&line);
	return (ret);
}

/*
 **			get nbr ants 	
 **	if not well formated >ther's a caracter or move than one intmax_t <
 **					return ERROR_FORMAT					 -1
 **
 **	if val < 1 
 ** 				return ERROR_VAL						 -2
 **
 ** if the next line is a vslur that can be considred like nbr ants 
 **					return ERROR_DUPLICAT_VAL_ANT		 -3
 */

intmax_t		ft_get_nbr_ants(t_charlist *line)
{
	intmax_t nbr_ants;

	if (!ft_isnumerique(line->data) || ft_comptword(line->data, ' ') != 1)
		return (ERROR_FORMAT);
	nbr_ants = ft_atointmax(line->data);
	if ( nbr_ants < 1)
		return (ERROR_VAL);
	line = line->next;
	if (ft_comptword(line->data, ' ') == 1 && ft_isnumerique(line->data))
		return (ERROR_DUPLICATS_VAL_ANT);
	return (nbr_ants);		
}

void	error_ants(int error)
{
	ft_printf("error nbr ants id error %d\n", error);
	exit(1);
}

void	error_room(int error)
{
	ft_printf("error room id error %d\n", error);
	exit(1);
}


t_node	*ft_get_room(char *str, int id_room)
{
	t_node *ret;
	char *name;
	char *x;
	char *y;

	if (ft_comptword(str, SP) != 3)	
		return (NULL);
	name  = ft_getword(str, 0, ' ');
	if (ft_is_c_in_str('-', name))
		error_room(ERROR_NAME_ROOM_FORMAT);
	ret = ft_new_node(id_room, name, 0, 0);


	x = ft_getword(str, 1, ' ');
	y = ft_getword(str, 2, ' ');
	if (!ft_isnumerique(name) || !ft_isnumerique(y))
		error_room(ERROR_COORDINATES_ROOM_FORMAT);
	ret->x = ft_atointmax(x);
	ret->y = ft_atointmax(y);

	

//	free (name);
//	ft_strdel(&name);		
	ft_strdel(&x);		
	ft_strdel(&y);		

///	free   y    name*2

	return (ret);
}

/*
**	voir pour tout les cas de break si j'ai des leaks 
*/
t_charlist	*ft_get_room_graph(t_map *map, t_charlist	*line,
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
		if (is_start(line->data))
		{
				if ( is_end((line->next)->data) ||
			!(temp_node = ft_get_room((line->next)->data, cp)))
				break; //exit(1);
			else
				map->start = cp;
			line = line->next;
		}
		else if (is_end(line->data))
		{
			if ( is_start((line->next)->data) ||
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
		{				//error_room(ERROR_NAME_ROOM_EXISTS);
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

void	error_links(int error)
{
	ft_printf("error links id error %d\n", error);
	exit(1);
}

void	ft_get_links_room_graph(t_charlist *links, t_nodelist *listnodes)
{
	char *name1;
	char *name2;

	while (links)
	{
	//		ft_printf(" %s \n", links->data);
		if (ft_is_c_in_str('-', links->data))
		{

			if (ft_comptword(links->data, '-') != 2)	
				error_links(ERROR_FORMAT_LINK);

			name1  = ft_getword(links->data, 0, '-');
			name2  = ft_getword(links->data, 1, '-');
			
/*	ft_printf("%s   %s \t <%s>  len %d  %d  %d \n",name1, name2, links->data,
			ft_strlen(name1)	,ft_strlen(name2),ft_strlen(links->data));
*/	
	if ((ft_strlen(name1) + ft_strlen(name2) + 1) != ft_strlen(links->data))
				error_links(ERROR_FORMAT_LINK);



			if (!ft_is_name_in_nodelist(name1, listnodes))
				error_links(ERROR_FORMAT_LINK_NAME);
			if (!ft_is_name_in_nodelist(name2, listnodes))
				error_links(ERROR_FORMAT_LINK_NAME);

			ft_add_neighbors(listnodes, name1, name2);

			ft_strdel(&name1);		
			ft_strdel(&name2);		
		}
		else
			error_links(ERROR_FORMAT_LINK);
		links = links->next;
	}
}

void	ft_extract_info_file(t_charlist *file, t_map *map)
{
	t_charlist	*line;
	t_charlist	*links;
	t_nodelist  *listnodes;

	listnodes = NULL;	
	line = file;
	ft_printf("/ **************** nbr ants ******************* \\ \n");
	if ((map->nbr_ants = ft_get_nbr_ants(line)) < 0)
		error_ants(map->nbr_ants);
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
	file = first_passe();
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
