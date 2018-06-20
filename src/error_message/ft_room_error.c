/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:02:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 15:58:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_room_error(int error, char *line)
{
	if (error == ERROR_NO_START_END_ROOM)
		ft_printf("Error line <%s> \nno information found about start/end room"
				"\n<Error room id %d>\n", line, error);
	else if (error == ERROR_NO_START_ROOM_DECLARED)
		ft_printf("Error start room \nno starting room declared\n"
				"<Error room id %d>\n", error);
	else if (error == ERROR_NO_END_ROOM_DECLARED)
		ft_printf("Error end room \nno ending room declared\n"
				"<Error room id %d>\n", error);
	else if (error == ERROR_NAME_ROOM_FORMAT)
		ft_printf("Error line <%s> \nthe name of the room must be a block"
				" with out '-' in it and don't start with 'L'.\n"
				"<Error room id %d>\n", line, error);
	else if (error == ERROR_FORMAT_LINE)
		ft_printf("Error line <%s> \nBad format line room <Error syntax id the"
				" name should not contain ' ' in it.\n"
				"<Error room id %d>\n", line, error);
	if (error == ERROR_COORDINATES_ROOM_FORMAT)
		ft_printf("Error coordinates room <%s>\n<Error room id %d>.\n",
				line, error);
	if (error == ERROR_COORDINATES_ROOM_EXIST)
		ft_printf("Error coordinates room <%s> existe.\n<Error syntax id %d>\n",
				line, error);
	exit(1);
}
