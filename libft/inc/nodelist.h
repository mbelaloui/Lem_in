/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodelist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:57:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 18:31:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODELIST_H
# define NODELIST_H

# include "node.h"

typedef struct			s_nodelist
{
	t_node				*node;
	struct s_nodelist	*next;
}						t_nodelist;

t_nodelist				*ft_new_nodelist(t_node *node);
BOOL					ft_add_end_list_nodelist(t_node *node,
		t_nodelist **list);
void					ft_put_list_nodelist(t_nodelist *list);
BOOL					ft_is_empty_nodelist(t_nodelist *list);
BOOL					ft_dell_bgn_nodelist(t_nodelist **list);
BOOL					ft_clear_list_nodelist(t_nodelist **list);

BOOL					ft_is_coord_in_nodelist(int x, int y, t_nodelist *list);
BOOL					ft_is_name_in_nodelist(char *nom, t_nodelist *list);
int						ft_get_id_node(char *node_name, t_nodelist *listnode);

void					ft_add_neighbors(t_nodelist *listnode, char *node_name,
		char*neighbor);
BOOL					ft_exist_node_nodelist(t_node *node,
		t_nodelist *listnodes);
int						ft_size_nodelist(t_nodelist *listnode);
t_node					*ft_get_node_listnode(t_nodelist *listnode, int id);
int						ft_find_path_deep(t_nodelist *listnodes, t_node *node,
		t_node *end, t_int_list **path);
int						ft_find_path_width(t_nodelist *listnodes,
		t_node *node,t_node *end, t_int_list **path);

void					ft_reste_status_listnode(t_nodelist *listnode);
t_int_list				*ft_get_father(int id_end, t_nodelist *listnode);
intmax_t				ft_get_id_best_father(t_int_list *list_fathers,
		t_nodelist *listnode);
intmax_t				ft_get_id_best_father(t_int_list *list_fathers,
		t_nodelist *listnode);
t_int_list				*ft_backtrack_path(t_nodelist *listnode, int id_end,
		int id_start);





#endif
