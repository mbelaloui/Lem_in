/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:23:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:31:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

int	ft_move_ant(t_ant *ant, t_int_list *path, t_nodelist *listnode, t_map map)
{
	int	id_nextroom;
	int	pos;
	int	nbr;

	nbr = 0;
	pos = ant->pos;
	if ((id_nextroom = ft_is_next_step_free(pos, path, listnode, map.end)) > -1)
	{
		if (ant->pos != 0)
			ft_set_room_free(listnode, ant->pos);
		ant->pos = id_nextroom;
		if (id_nextroom != map.end)
			ft_set_taken_room(id_nextroom, listnode);
		ft_put_ant(ant, listnode);
		if (ant->pos == map.end)
			nbr++;
	}
	return (nbr);
}
