/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:41:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 18:11:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

static BOOL		good_format_line(char *str)
{
	char *name;

	if (ft_comptword(str, SP) > 3)
	{
		ft_room_error(ERROR_FORMAT_LINE, str);
		return (F);
	}
	if (ft_comptword(str, SP) != 3)
		return (F);
	name = ft_getword(str, 0, ' ');
	if ((ft_is_c_in_str('-', name) || name[0] == 'L') && ft_strdel(&name))
		ft_room_error(ERROR_NAME_ROOM_FORMAT, str);
	ft_strdel(&name);
	return (T);
}

static void		is_good(char *name, intmax_t x, intmax_t y)
{
	if (x < MIN_INT || x > MAX_INT)
		ft_room_error(ERROR_COORDINATES_ROOM_FORMAT, name);
	if (y < MIN_INT || y > MAX_INT)
		ft_room_error(ERROR_COORDINATES_ROOM_FORMAT, name);
}

t_node			*ft_get_room(char *str, int id_room)
{
	t_node	*ret;
	char	*name;
	char	*x;
	char	*y;

	if (!good_format_line(str))
		return (NULL);
	name = ft_getword(str, 0, ' ');
	ret = ft_new_node(id_room, name, 0, 0);
	x = ft_getword(str, 1, ' ');
	y = ft_getword(str, 2, ' ');
	if (!ft_isnumerique(x) || !ft_isnumerique(y))
	{
		ft_room_error(ERROR_COORDINATES_ROOM_FORMAT, name);
		return (NULL);
	}
	ret->x = ft_atointmax(x);
	ret->y = ft_atointmax(y);
	is_good(name, ret->x, ret->y);
	ft_strdel(&x);
	ft_strdel(&y);
	return (ret);
}
