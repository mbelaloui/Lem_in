/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_passe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:31:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:39:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

/*
** first passe read the file and ignor the commants
**
**i	f (empty line)
**return (ERROR_EMPTY_LINE)
 **
 ** if (##start) found twice separate in the file or not found
* **return (ERROR_START_FORMAT)
* **
* ** if (##end) found twice separate in the file or not found
* **return (ERROR_END_FORMAT)
* **
* **for not found may be make an other case of error.....
* **
* ** return a linked list of line <char *>
* */

t_charlist		*ft_first_passe()
{
	t_charlist *ret;
	char *line;
	char *temp;
	BOOL  s;
	BOOL  e;

	s = F;
	e = F;
	line = NULL;
	ret = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_strlen(line))
			ft_syntax_error(ERROR_EMPTY_LINE);
		if (ft_is_start(line))
		{
			if (s)
				ft_syntax_error(ERROR_START_FORMAT);
			else
			{
				temp = ft_format_str(line);
				ft_add_charlist(temp, &ret);
				ft_strdel(&temp);
				ft_strdel(&line);
				while (get_next_line(0, &line) &&
						(ft_is_start(line) || ft_is_comment(line)))
					ft_strdel(&line);
			}
			s = T;
		}
		if (ft_is_end(line))
		{
			if (e)
				ft_syntax_error(ERROR_END_FORMAT);
			else
			{
				temp = ft_format_str(line);
				ft_add_charlist(temp, &ret);
				ft_strdel(&temp);
				ft_strdel(&line);
				while (get_next_line(0, &line) &&
						(ft_is_end(line) || ft_is_comment(line)))
					ft_strdel(&line);
			}
			e = T;
		}
		if (!ft_is_comment(line))
		{
			temp = ft_format_str(line);
			ft_add_charlist(temp, &ret);
			ft_strdel(&temp);
		}
		ft_strdel(&line);
	}
	if (!s)
		ft_syntax_error(ERROR_NO_START);
	if (!e)
		ft_syntax_error(ERROR_NO_END);
	if (!ret)
		ft_syntax_error(ERROR_EMPTY_FILE);
	ft_strdel(&line);
	return (ret);
}
