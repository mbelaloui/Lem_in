/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_best_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:14:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:50:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_put_best_path(t_int_list *path, t_nodelist *listnode, t_option op)
{
	ft_printf("--------***** the best path ****--------\n");
	if (op.r)
	{
		while (path)
		{
			ft_put_node(ft_get_node_listnode(listnode, path->data));
			path = path->next;
		}
	}
	else
		ft_put_intlist(path);
}
