/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:00:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/15 12:48:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_ants_error(int error)
{
	if (error == ERROR_FORMAT_NBR_ANTS)
		ft_printf("Error numbers of ants not in the beginning of the file"
				"\n<Error nbr ants id %d>\n", error);
	else if (error == ERROR_NULL_VAL_NBR_ANTS)
		ft_printf("Error numbers of ants may not be null"
				"\n<Error nbr ants id %d>\n", error);
	else if (error == ERROR_NEGATIVE_VAL_NBR_ANTS)
		ft_printf("Error numbers of ants may not be negative"
				"\n<Error nbr ants id %d>\n", error);
	else if (error == ERROR_DUPLICATS_VAL_ANTS)
		ft_printf("Error numbers of ants should be unique"
				"\n<Error nbr ants id %d>\n", error);
	else
		ft_printf("error nbr ants id error %d\n", error);
	exit(1);
}
