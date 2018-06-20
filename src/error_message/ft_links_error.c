/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:03:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 17:54:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_links_error(int error, char *line)
{
	if (error == ERROR_FORMAT_LINK)
		ft_printf("Error line <%s> \nthe link is not well formated"
				"\n<Error links id %d>.\n", line, error);
	else if (error == ERROR_LINK_NAME_ROOM)
		ft_printf("Error name room <%s>.\n"
			"the name doesn't existe.\n<Error links id %d>.\n", line, error);
	else if (error == ERROR_NO_LINKS)
		ft_printf("Error links room.\nno links between rooms in the "
				"file\n<Error links id %d>.\n", error);
	else if (error == ERROR_LINK_ROOM_ROOM)
		ft_printf("Error name room <%s-%s> \n"
				"a room can't be linked to itself.\n"
				"<Error links id %d>.\n", line, line, error);
	else
		ft_printf("error links id error.%d\n", error);
	exit(1);
}
