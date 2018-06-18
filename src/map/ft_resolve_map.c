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




/***********************************************/
static void	erro_map(void)
{
	ft_printf("no enough data to find a path\n");
	exit(1);
}




/***********************************************/
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




/***********************************************/
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




/***********************************************/
//  changer le nom en exploration en profnodeure 
int	explore_graph(t_nodelist *listnodes, t_node *node,t_node *end, t_int_list **path)
{
	t_node *temp;
	t_int_list *list = node->list_neighbors;

	ft_printf("id node =%d  id end = %d\n",node->id, end->id);
	if (node->id == end->id)
		return 1;
	node->stats = 1;
	ft_put_node(node);
	while (list)
	{
		temp = ft_get_node_listnode(listnodes, list->data);
		
		if (temp->stats == 0)
		{
//			ft_add_end_intlist(node->id, path);
			ft_add_end_intlist(temp->id, path);
			if (explore_graph(listnodes, temp,end, path))
				return 1;
		}
		list =list->next;
	}
	ft_dell_end_int_list(path);
	
	return (0);
}


int	explore_graph_2(t_nodelist *listnodes, t_node *node,t_node *end, t_int_list **path)
{
	t_node *temp;
	t_int_list *list = node->list_neighbors;
	node->stats = 1;


	ft_printf("------------ 1 -------------- \n");
//	ft_put_int_list(*path);
	while (list)
	{
		temp = ft_get_node_listnode(listnodes, list->data);
		if (temp->stats == 0)
		{
			temp->dist  = node->dist + 1;
			ft_add_end_intlist(temp->id, path);
		}
		list =list->next;
		if (node->id == end->id)
		{
			ft_clear_intlist(path);
			return 1;
		}
	}
//	ft_printf("------------ 2 -------------- \n");
//	ft_put_int_list(*path);
	ft_dell_bgn_int_list(path);	
	ft_put_int_list(*path);
	
	 while (*path)
	{
		temp = ft_get_node_listnode(listnodes, (*path)->data);
		if (explore_graph_2(listnodes, temp,end, path))
			return (1);
		else
			if (*path)
				*path = (*path)->next;
	}
//		return 1;
//		ft_dell_end_int_list(path);

	ft_printf("------------ -------------- \n");
	(void) end;	
	return (0);
}




/***********************************************/
void	reste_status_listnode(t_nodelist *listnode)
{
	while (listnode)
	{
		listnode->node->stats = 0;
		listnode = listnode->next;
	}
}



/***********************************************/
t_int_list	*ft_get_father(int id_end, t_nodelist *listnode)
{
	t_int_list *list_id_father;
	t_int_list *temp;

	list_id_father = NULL;
	while (listnode)
	{
		temp = listnode->node->list_neighbors;
		if (ft_is_in_int_list(id_end, temp))
		{
			ft_add_end_intlist(listnode->node->id, &list_id_father);
			
		}
		listnode = listnode->next;
	}
	return (list_id_father);
}





/***********************************************/
intmax_t		ft_get_id_best_father(t_int_list *list_fathers, t_nodelist *listnode)
{
	intmax_t best_dist;
	intmax_t best_id;
	t_node	*temp_node;

	if (!list_fathers)
		return (-1);
	temp_node = ft_get_node_listnode(listnode, list_fathers->data);
	best_dist = temp_node->dist;
	best_id = temp_node->id;
	list_fathers = list_fathers->next;
	while (list_fathers && best_dist)
	{

temp_node = ft_get_node_listnode(listnode, list_fathers->data);	


		if (temp_node->dist < best_dist)
		{
			best_id = temp_node->id;
			best_dist = temp_node->dist;
		}
		list_fathers = list_fathers->next;
	}
	return (best_id);
}





/***********************************************/
t_int_list	*ft_backtrack_path(t_nodelist *listnode, int id_end)
{
	t_int_list *list_father;
	int id_father;
	t_int_list *path;

	path = NULL;
	ft_add_bgn_intlist(id_end, &path);
	list_father = ft_get_father(id_end, listnode);
	while ( (id_father = ft_get_id_best_father(list_father, listnode)) > -1
 && id_father)
	{
		ft_add_bgn_intlist(id_father, &path);
		list_father = ft_get_father(id_father, listnode);
	}
	return (path);
}


t_ant	*ft_new_ant(int id, int pos)
{
	t_ant *ret;
	
	if (!(ret = malloc(sizeof(*ret))))
                return (NULL);
        ret->id = id;
        ret->pos = pos;
        ret->next = NULL;
        return (ret);
}

BOOL    ft_add_end_antlist(int id, int pos, t_ant **list)
{
        t_ant      *temp_node;
        t_ant      *pt_list;

        if (!(temp_node = ft_new_ant(id, pos)))
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

BOOL    ft_is_empty_antlist(const t_ant *list)
{
        return ((list) ? F : T);
}

void    ft_put_antlist(const t_ant *list, t_nodelist *listnode)
{
       	t_node *node;

	 if (ft_is_empty_antlist(list))
                ft_printf("[∅].\n");
        else
        {
                ft_printf("[");
                while (list)
                {
			node = ft_get_node_listnode(listnode, list->pos);
                        ft_printf("%L%ld-%s", list->id, node->name);
                        list = list->next;
                        if (list)
                                ft_printf(",");
			//free node;
                }
                ft_printf("].\n");
        }
}

/***********************************************/
void	ft_resolve_map(t_map map, t_nodelist *listnode)
{
	t_int_list *path;
	
	
	path = NULL;
	if (map.nbr_ants < 1 || map.start < 0 || map.end < 0 || !listnode)
		erro_map();
	int nbr_room;
	ft_printf("/ ********************* algorithme **************************** \\\n");

	ft_printf("size node list < room > %d \n", nbr_room = ft_size_nodelist(listnode));

	t_node *start;
	t_node *end;
	start = ft_get_node_listnode(listnode, map.start);
	end = ft_get_node_listnode(listnode, map.end);
	ft_add_end_intlist(map.start, &path);
	explore_graph(listnode, start,end, &path);
	ft_put_int_list(path);

	while (path)
	{
		t_node *temp;
		temp = ft_get_node_listnode(listnode, path->data);
		ft_printf("%s\n", (temp->name));
		path = path->next;
	}
	
	ft_printf("/ ********************* 1 **************************** \\\n");
//	ft_put_list_nodelist(listnode);
	ft_printf("/ ********************* 2 **************************** \\\n");
	//ft_temporize(2);
	reste_status_listnode(listnode);
	ft_clear_intlist(&path);
	path = NULL;
	ft_add_end_intlist(map.start, &path);
	explore_graph_2(listnode, start,end, &path);
	ft_put_list_nodelist(listnode);


	ft_printf("/ ********************* list_father **************************** \\\n");

	t_int_list *list_father;
	list_father = ft_get_father(map.end, listnode);

	

	ft_put_int_list(list_father);
	
	int id_father = ft_get_id_best_father(list_father, listnode);
	ft_printf("best fathers is %d \n", id_father);

	t_int_list	*q_path = ft_backtrack_path(listnode, map.end);

	ft_add_bgn_intlist(map.start, &q_path);

	ft_printf("-----------------************************---------------------------\n");
	ft_put_int_list(q_path);

	while (q_path)
	{
		ft_put_node(ft_get_node_listnode(listnode, q_path->data));
		q_path = q_path->next;
	}

	int id = 0;
	t_ant *listants = NULL;
	while (id < map.nbr_ants)
	{
		ft_add_end_antlist(id, map.start, &listants);
		id++;
	}

	ft_put_antlist(listants, listnode);	

	// reset stat to the rooms witch are'nt in the list and repeat intil ther's
	// no room to reset or the path is empty
	// init tab ants     
	// mettre le nom L_id
	// position
	/* faire une fonction qui va prendre une liste de fourmie et le tableu de path
	va detecter la position de la fourmis puis 
	voir si la fourmis peut avancer
	si la foumis peut avancer  room libre 
		{
			 changer emplassement fourmis
			librer room 
			mettre nouvelle roume occuper
		}
	si non euuuu voila retourner // passer la fouemis suivante
	*/ 

/*	int cp = 0;
	while (cp < nbr_room)
	{
		ft_put_node(ft_get_node_listnode(listnode, cp));
		cp++;
	}*/


/*	t_int_list *list;

	list = NULL;
	ft_put_int_list(list);
	node = ft_get_node_listnode(listnode, map.start);
	ft_add_end_intlist(map.start, &list);
	ft_put_int_list(list);

	while (list)
	{

	}

*/

}





































