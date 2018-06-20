/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:08:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:22:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_put_help(void)
{
	ft_printf("lem-in help\n"
			"\n"
			"\t\t./lem-in -b   to display the id of best path rooms.\n"
			"\t\t./lem-in -f   to display the file without comments.\n"
			"\t\t./lem-in -h   to display this messgae.\n"
			"\t\t./lem-in -l   to display the links between rooms in the map.\n"
			"\t\t./lem-in -m   to display a description of the map.\n"
			"\t\t./lem-in -r   to display the rooms of the map.\n"
			"\t\t./lem-in -u   to display the usage.\n"
			"\n\t\ttips : -u and -b to display the description of the best "
				"path rooms.\n");
	exit(1);
}
