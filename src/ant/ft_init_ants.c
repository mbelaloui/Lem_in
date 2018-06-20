/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:47:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 21:13:06 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

t_ant	*ft_init_ants(intmax_t nbr_ants, intmax_t id_room)
{
	t_ant		*listants;
	intmax_t	id;

	id = 1;
	listants = NULL;
	while (id <= nbr_ants)
	{
		ft_add_end_antlist(id, id_room, &listants);
		id++;
	}
	return (listants);
}
