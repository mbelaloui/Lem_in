/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:57:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/14 20:26:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

static void	empty_line(int error)
{
	if (error == ERROR_EMPTY_LINE)
		ft_printf("{RED}WRNING empty line <Error syntax id %d>\n"
			"the program may not have read the entire file{eoc}.\n", error);
	else if (error == ERROR_DUPLICAT_START_ROOM)
		ft_printf("Error two starting rooms found\n<Error syntax id %d>\n",
					error);
	else if (error == ERROR_DUPLICAT_END_ROOM)
		ft_printf("Error two ending rooms found\n<Error syntax id %d>\n",
					error);
}

void		ft_syntax_error(int error)
{
	if (error > ERROR_NO_END)
		empty_line(error);
	else
	{
		if (error == ERROR_EMPTY_FILE)
			ft_printf("Error The file is empty <Error syntax id %d>\n", error);
		else if (error == ERROR_NO_START)
			ft_printf("Error ther's no start room <Error syntax id %d>\n",
					error);
		else if (error == ERROR_NO_END)
			ft_printf("Error ther's no end room <Error syntax id %d>\n", error);
		else
			ft_printf(" <Error syntax id %d>\n", error);
		exit(1);
	}
}
