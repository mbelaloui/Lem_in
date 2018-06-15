/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:46:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/07 11:02:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lim_in.h"

t_node		*ft_new_node(int id, char *name, intmax_t x, intmax_t y)
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

void	ft_put_map(t_map *map)
{
	ft_printf("nbr of ants %d \n", map->nbr_ant);
}

void	ft_put_node(t_node * node)
{
	t_int_list *pt_lngbrs;

	ft_printf("id node    : %d \n", node->id);
	ft_printf("name node  : %s \n", node->name);
	ft_printf("stats node : %d \n", node->stats);
	ft_printf("spacial coordinats { %ld, %ld }\n", node->x, node->y);
	pt_lngbrs = node->list_neighbors;
	if (ft_is_empty_int_list(pt_lngbrs))
		ft_printf("[∅].\n");
	else
	{
		while (pt_lngbrs)
		{
			ft_printf("id neighbors node %ld\n", pt_lngbrs->data);
			pt_lngbrs = pt_lngbrs->next;
		}
	}
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

BOOL	ft_isnumerique(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		if ((str[i] == '+' || str[i] == '-') && (ft_isdigit(str[i + 1])))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		ft_printf(">%c<  str i >%d<\n", str[i], str[i]);

		return ((!ft_isalpha(str[i]) 
		&& (str[i] == 0 || ft_isdigit(str[i])) )  ? T : F);
	}
	return (F);
}

BOOL	ft_get_nbr_ant(t_map *map)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) && is_comment(line))
		ft_printf("%s\n", line);
	if (!ft_strlen(line))
	{
		ft_printf("empty file\n");
		exit(1);
	}
	ft_printf("/*******************nbr ants***********************/\n");
	ft_printf("%s\n", line);
	if (ft_isnumerique(line) && !ft_is_overflow_intmax(line))
	{
		map->nbr_ant = ft_atointmax(line);
		ft_printf("nbr ants =  %ld\n", map->nbr_ant);
		if (map->nbr_ant > 0)
			return (T);
	}
	if (ft_is_overflow_intmax(line))
		ft_printf("long overflow nbr ants\n");
	else
		ft_printf("wrong format of number ants\n");
	exit (1);
}

/*BOOL	is_path(char *str)
  {

  }
  */
BOOL	is_good_format_room_info(char *str)
{
	ft_printf(" nbr mots %d\n", ft_comptword(str, SP));
	if (ft_comptword(str, SP) != 3)
		return (F);
	return (T);
}

t_listnode		*ft_new_listnode(t_node *node)
{
	t_listnode *ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->node = node;
	ret->next = NULL;
	return (ret);
}

BOOL	ft_add_end_list_listnode(t_node *node, t_listnode **list)
{
	t_listnode	*temp_node;
	t_listnode	*pt_list;

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

void	ft_put_list_listnode(t_listnode *list)
{
	while (list)
	{
		ft_put_node(list->node);
		list = list->next;
	}
}

BOOL	ft_is_empty_listnode(t_listnode *list)
{
	return ((list) ? F : T);
}

BOOL	ft_is_in_listcode(char *nom, t_listnode *list)
{
	while(list)
	{
		if (!ft_strcmp(nom, list->node->name))
			return (T);
		list = list->next;
	}
	return (F);
}

BOOL	ft_get_room(t_map *map)
{
	char *line;
	char *temp_line;
	//	char *word;
	int cp;
	int num_line;
	t_node *temp_node;
	t_listnode	*listnodes;

	//	t_listnode *list;

	(void)map;
	ft_printf("\n/****************** lecture room ************************/\n");
	listnodes = NULL;
	line = NULL;
	num_line = 0;
	while (get_next_line(0, &line))
	{
		if (!is_comment(line))
		{
			if (!is_start(line) && !is_end(line))
			{
				temp_line = ft_format_str(line);
				if (!is_good_format_room_info(temp_line))
					break;
				else
				{
					cp = 0;
					while (cp < 3)
					{
				
					char *nom = ft_getword(temp_line, 0, ' ');
					char *char_x = ft_getword(temp_line, 1, ' ');
					char *char_y = ft_getword(temp_line, 2, ' ');
				
					if (ft_is_in_listcode(nom, listnodes))
					{
						ft_printf("double \n");
						exit(1);
					}
					ft_printf(" char x = %s   char y = %s\n", char_x, char_y);

					if (!ft_isnumerique(char_x) || !ft_isnumerique(char_y))
					{
						ft_printf("{green}wrong format coordinates{eoc}\n");
						exit(1);
					}

					int x = ft_atointmax(char_x);
					int y = ft_atointmax(char_y);
				temp_node = ft_new_node(num_line, nom, x, y);

					ft_add_end_list_listnode(temp_node, &listnodes);

//			ft_put_node(temp_node);
					num_line++;
					cp = 3;
					}
				}
			}
			else
			{
				if (is_start(line))
					ft_printf("{GREEN}start{eoc}");
				else
					ft_printf("{GREEN}end{eoc}");
			}
		}else
			ft_printf("{YELLOW}commentaires room name{EOC}\n");
	}
	if (ft_comptword(temp_line, SP) > 3)
	{
		ft_printf("{red}wrong format info room{eoc}\n");
		exit (1);
	}

	ft_printf("\n/******************room************************/\n");

	if (ft_is_empty_listnode(listnodes))
	{
		ft_printf("no rooms !!!");
		exit (1);
	}

	ft_put_list_listnode(listnodes);

	return (T);
}



void	ft_int_map(t_map *map)
{
	map->nbr_ant = 0;
}

void	read_map()
{
	t_map map;
	char *line;

	line = NULL;
	/*
	 ** lecture du nombre de fourmis
	 ** prendre en compt les commentaires
	 */
	ft_int_map(&map);
	ft_get_nbr_ant(&map);
	/*	if (!
		)
		{
		exit(1);
		}
		*/
	/*
	 ** lecture des noms et des coordonnees de salles
	 ** prendre en compt les commentaires
	 */
//	ft_get_room(&map);

	/*	int i = 1;
		while (get_next_line(0, &line))
		{
		ft_printf("%s\n", line);

		if (is_start(line))
		ft_printf("%d start  \n", i,line);
		if (is_comment(line))
		ft_printf("%d commentaire\n",i, line);
		if (is_end(line))
		ft_printf("%d end\n", i,line);
		i++;
		}
		*/

	/*
	 ** lecture des tubes
	 ** prendre en compt les commentaires
	 */

}

int		main(void)
{
/*	t_node *node_1;
	t_node *node_2;
	t_node *node_3;
	t_node *node_4;
	t_node *node_5;
	t_node *node_6;

	node_1 = ft_new_node(1, "node 1", 1, 1);
	node_2 = ft_new_node(2, "node 2", 2, 2);
	node_3 = ft_new_node(3, "node 3", 3, 3);
	node_4 = ft_new_node(4, "node 4", 4, 4);
	node_5 = ft_new_node(5, "node 5", 5, 5);
	node_6 = ft_new_node(6, "node 6", 6, 6);

	ft_put_node(node_1);



	ft_printf("/ ********************************************\\\n");
	
	   ft_add_end_intlist(2, &node_1->list_neighbors);
	   ft_add_end_intlist(3, &node_1->list_neighbors);
	   ft_add_end_intlist(4, &node_1->list_neighbors);
	   ft_add_end_intlist(6, &node_1->list_neighbors);



	   ft_put_node(node_1);
	   */


	read_map();
	return (0);
}
