/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:27:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 18:10:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_send_ants(t_ant *ants, t_int_list *path, t_nodelist *listnode,
		t_map map)
{
	t_ant	*save_ant;
	int		nbr;

	nbr = 0;
	ft_reste_status_listnode(listnode);
	save_ant = ants;
	while (nbr < map.nbr_ants)
	{
		ants = save_ant;
		while (ants)
		{
			nbr += ft_move_ant(ants, path, listnode, map);
			ants = ants->next;
		}
		ft_printf("\n");
	}
}
