/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:02:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/07 11:24:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lim_in.h"



t_node          *ft_new_node(int id, char *name, intmax_t x, intmax_t y)
{
	t_node *ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->id = id;
	ret->name = name;
	ret->x = x;
	ret->y = y;
	ret->stats = 0;
	ret->list_neighbors = NULL;
	return (ret);
}

void    ft_put_map(t_map *map)
{
	ft_printf("nbr of ants %d \n", map->nbr_ants);
	ft_printf("id of starting room %d \n", map->start);
	ft_printf("id of ending room %d \n", map->end);
}

void    ft_put_node(t_node * node)
{
	t_int_list *pt_lngbrs;

	ft_printf("id node    : %d\n", node->id);
	ft_printf("name node  : %s\n", node->name);
	ft_printf("stats node : %d\n", node->stats);
	ft_printf("spacial coordinats [%ld, %ld]\n", node->x, node->y);
	pt_lngbrs = node->list_neighbors;
	if (ft_is_empty_int_list(pt_lngbrs))
		ft_printf("list neighbors {∅}\n");
	else
	{
		ft_printf("id neighbors node {");
		while (pt_lngbrs)
		{
			if (pt_lngbrs->next)
				ft_printf("%ld, ", pt_lngbrs->data);
			else
				ft_printf("%ld", pt_lngbrs->data);
			pt_lngbrs = pt_lngbrs->next;
		}
		ft_printf("}.\n");
	}
}


t_listnode              *ft_new_listnode(t_node *node)
{
	t_listnode *ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->node = node;
	ret->next = NULL;
	return (ret);
}

BOOL    ft_add_end_list_listnode(t_node *node, t_listnode **list)
{
	t_listnode      *temp_node;
	t_listnode      *pt_list;

	if (!node || ! (temp_node = ft_new_listnode(node)))
		return (F);
	if (!(*list))
		*list = temp_node;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp_node;
	}
	return (T);
}

void    ft_put_list_listnode(t_listnode *list)
{
	while (list)
	{
		ft_put_node(list->node);
		list = list->next;
	}
}

BOOL    ft_is_empty_listnode(t_listnode *list)
{
	return ((list) ? F : T);
}

BOOL		ft_dell_node(t_node **node)
{
	t_int_list	*to_free_list;
	char			*to_free_name;

	if (node && *node)
	{
		
		to_free_name =  (*node)->name;
		ft_strdel(&to_free_name);
		to_free_list = (*node)->list_neighbors;
		ft_clear_intlist(  &to_free_list  );
		free(*node);
		return (T);
	}
	return (F);
}

BOOL    ft_dell_bgn_listnode(t_listnode **list)
{
        t_listnode      *to_free;

        if ((*list) == NULL)
                return (F);
        to_free = *list;
        if (!(*list)->next)
                *list = NULL;
        else
                *list = (*list)->next;
        ft_dell_node(&(to_free->node));
        free(to_free);
        return (T);
}




BOOL	ft_clear_list_lisitnode(t_listnode **list)
{
	if (list && *list)
	{
		while (*list)	
			ft_dell_bgn_listnode(list);	
		return (T);
	}

	return (F);
}


























/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
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

BOOL    ft_isnumerique(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		if ((str[i] == '+' || str[i] == '-') && (ft_isdigit(str[i + 1])))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		return ((!ft_isalpha(str[i]) 
					&& (str[i] == 0 || ft_isdigit(str[i])) )  ? T : F);
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

BOOL    ft_is_coord_in_listnode(int x, int y, t_listnode *list)
{
	while(list)
	{
		if (list->node->x == x && list->node->y == y)
			return (T);
		list = list->next;
	}
	return (F);
}

BOOL    ft_is_name_in_listnode(char *nom, t_listnode *list)
{
	while(list)
	{
		if (!ft_strcmp(nom, list->node->name))
			return (T);
		list = list->next;
	}
	return (F);
}
/*
BOOL    ft_is_cord_in_listnode(char *nom, t_listnode *list)
{
	while(list)
	{
		if (!ft_strcmp(nom, list->node->name))
			return (T);
		list = list->next;
	}
	return (F);
}
*/
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

BOOL		ft_exist(t_node *node, t_listnode *listnodes)
{
	if (ft_is_name_in_listnode(node->name, listnodes))
		return (T);

	if (ft_is_coord_in_listnode(node->x, node->y, listnodes))
		return (T);
		//error_room(ERROR_COORDINATES_ROOM_EXIST);

	return (F);
}


/*
**	voir pour tout les cas de break si j'ai des leaks 
*/
t_charlist	*ft_get_room_graph(t_map *map, t_charlist	*line,
		t_listnode **lstnodes)
{
	t_listnode      *listnodes;

	t_node *temp_node;
	int cp;
	listnodes = NULL;	
	cp = 0;
		ft_put_list_listnode(listnodes);
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
		if (ft_exist(temp_node, listnodes))
		{				//error_room(ERROR_NAME_ROOM_EXISTS);
			ft_dell_node( &temp_node);
			break;		
		}
		else
			ft_add_end_list_listnode(temp_node, &listnodes);
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

int		ft_get_id_node(char *node_name, t_listnode *listnode)
{
	int ret;

	ret = -1;
	while (listnode && ft_strcmp(node_name, listnode->node->name))
		listnode = listnode->next;
	
	if (listnode)
		ret = listnode->node->id ;

	return (ret);	
}

void		ft_add_neighbors(t_listnode *listnode, char *node_name, char*neighbor)
{
	int	id_neighbor;

	id_neighbor = ft_get_id_node(neighbor, listnode);
//	ft_printf("   id neighbor = %d  \n", id_neighbor);

	while (listnode && ft_strcmp(node_name, listnode->node->name))
		listnode = listnode->next;

	if (listnode)
		ft_add_end_intlist(id_neighbor, &listnode->node->list_neighbors);

	
	(void)node_name;
}


void	ft_get_links_room_graph(t_charlist *links, t_listnode *listnodes)
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

			ft_printf("%s   %s \n",name1, name2);


			if (!ft_is_name_in_listnode(name1, listnodes))
				error_links(ERROR_FORMAT_LINK_NAME);
			if (!ft_is_name_in_listnode(name2, listnodes))
				error_links(ERROR_FORMAT_LINK_NAME);

			ft_add_neighbors(listnodes, name1, name2);

			ft_strdel(&name1);		
			ft_strdel(&name2);		

			/*
		
				while (name ! list name )
				{
					
				}
				add id list neigbors to node
			*/
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
	t_listnode  *listnodes;

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
	

	ft_put_list_listnode(listnodes);
	ft_clear_list_lisitnode(&listnodes);

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
