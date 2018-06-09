/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodelist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:57:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/09 11:45:07 by mbelalou         ###   ########.fr       */
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

#endif
