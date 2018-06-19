/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erro_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:03:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:39:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

// a continuer voir les erruer et affihcer les message corecpondant

void	ft_erro_map(int error)
{
	if (error == ERROR_NO_ENOUGH_DATA)
		ft_printf("the programme don't have enough data to do the job\n"
				"<Error syntax id %d>\n", error);
	else if (error == ERROR_NO_PATH)
		ft_printf("there is no path between start and end\n"
				"<Error syntax id %d>\n", error);
	else
		ft_printf("Error map <Error syntax id %d>\n", error);
	exit(1);
}
