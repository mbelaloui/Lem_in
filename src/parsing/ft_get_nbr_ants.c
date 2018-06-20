/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:39:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/15 12:49:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

/*
**get nbr ants
**if not well formated >ther's a caracter or move than one intmax_t <
**return ERROR_FORMAT -1
**
** if val < 1
**return ERROR_VAL -2
**
** if the next line is a vslur that can be considred like nbr ants
**return ERROR_DUPLICAT_VAL_ANT -3
*/

intmax_t	ft_get_nbr_ants(t_charlist *line)
{
	intmax_t nbr_ants;

	if (!ft_isnumerique(line->data) || ft_comptword(line->data, ' ') != 1)
		return (ERROR_FORMAT_NBR_ANTS);
	nbr_ants = ft_atointmax(line->data);
	if (!nbr_ants)
		return (ERROR_NULL_VAL_NBR_ANTS);
	if (nbr_ants < 0)
		return (ERROR_NEGATIVE_VAL_NBR_ANTS);
	line = line->next;
	if (ft_comptword(line->data, ' ') == 1 && ft_isnumerique(line->data))
		return (ERROR_DUPLICATS_VAL_ANTS);
	if ((MIN_INT < nbr_ants && nbr_ants < MAX_INT))
		return (nbr_ants);
	else
		return (ERROR_OVERFLOW_NBR_ANTS);
}
