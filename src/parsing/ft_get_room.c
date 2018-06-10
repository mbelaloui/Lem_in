/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:41:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:42:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

t_node		*ft_get_room(char *str, int id_room)
{
	t_node *ret;
	char *name;
	char *x;
	char *y;

	if (ft_comptword(str, SP) != 3)
		return (NULL);
	name  = ft_getword(str, 0, ' ');
	if (ft_is_c_in_str('-', name))
		ft_room_error(ERROR_NAME_ROOM_FORMAT);
	ret = ft_new_node(id_room, name, 0, 0);


	x = ft_getword(str, 1, ' ');
	y = ft_getword(str, 2, ' ');
	if (!ft_isnumerique(name) || !ft_isnumerique(y))
		ft_room_error(ERROR_COORDINATES_ROOM_FORMAT);
	ret->x = ft_atointmax(x);
	ret->y = ft_atointmax(y);



	//free (name);
	////ft_strdel(&name);		
	ft_strdel(&x);
	ft_strdel(&y);
	//
	/////free   y    name*2
	//
	return (ret)				;
}
