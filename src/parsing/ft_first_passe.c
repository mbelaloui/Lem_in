/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_passe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:31:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 18:15:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

/*
** first passe read the file and ignor the commants
**
**if (empty line)
**return (ERROR_EMPTY_LINE)
**
**if (##start) found twice separate in the file or not found
**return (ERROR_START_FORMAT)
**
** if (##end) found twice separate in the file or not found
**return (ERROR_END_FORMAT)
**
**for not found may be make an other case of error.....
**
** return a linked list of line <char *>
*/

/*
**  ft_printf("BOOL %d \tline %s\t temp %s\t ret %s\n",
**  *s, *line, *temp, (*ret)->data);
*/

static BOOL		start(BOOL *s, char **line, t_charlist **ret)
{
	char		*temp;

	if (*s)
	{
		ft_syntax_error(ERROR_DUPLICAT_START_ROOM);
		ft_printf("{RED}the program may not have read the entire file{eoc}.\n");
		return (F);
	}
	else
	{
		temp = ft_format_str(*line);
		ft_add_charlist(temp, ret);
		ft_strdel(&temp);
		ft_strdel(line);
		while (get_next_line(0, line)
				&& (ft_is_start(*line) || ft_is_comment(*line)))
		{
			ft_printf("%s\n", *line);
			ft_strdel(line);
		}
		ft_printf("%s\n", *line);
	}
	*s = T;
	return (T);
}

static BOOL		end(BOOL *e, char **line, t_charlist **ret)
{
	char		*temp;

	if (*e)
	{
		ft_syntax_error(ERROR_DUPLICAT_END_ROOM);
		ft_printf("{RED}the program may not have read the entire file{eoc}.\n");
		return (F);
	}
	else
	{
		temp = ft_format_str(*line);
		ft_add_charlist(temp, ret);
		ft_strdel(&temp);
		ft_strdel(line);
		while (get_next_line(0, line)
				&& (ft_is_end(*line) || ft_is_comment(*line)))
		{
			ft_printf("%s\n", *line);
			ft_strdel(line);
		}
		ft_printf("%s\n", *line);
	}
	*e = T;
	return (T);
}

static void		line_map(char *line, t_charlist **ret)
{
	char		*temp;

	temp = ft_format_str(line);
	ft_add_charlist(temp, ret);
	ft_strdel(&temp);
}

/*
** ft_printf("BOOL %d \tline %s\t temp %s\t ret %s\n",
**                    s, line, temp, (ret)->data);
*/

static void		end_reading(BOOL s, BOOL e, t_charlist *ret)
{
	if (!ret)
		ft_syntax_error(ERROR_EMPTY_FILE);
	if (!s)
		ft_syntax_error(ERROR_NO_START);
	if (!e)
		ft_syntax_error(ERROR_NO_END);
}

t_charlist		*ft_first_passe(void)
{
	t_charlist	*ret;
	char		*ln;
	BOOL		s;
	BOOL		e;
	int			r;

	s = F;
	e = F;
	ln = NULL;
	ret = NULL;
	while (ft_strdel(&ln) && (r = get_next_line(0, &ln)) && !ft_isempty(ln))
	{
		ft_printf("%s\n", ln);
		if (ft_is_start(ln) && !start(&s, &ln, &ret))
			break ;
		if (ft_is_end(ln) && !end(&e, &ln, &ret))
			break ;
		if (!ft_is_comment(ln))
			line_map(ln, &ret);
	}
	if (ft_isempty(ln) && r != 0)
		ft_syntax_error(ERROR_EMPTY_LINE);
	ft_strdel(&ln);
	end_reading(s, e, ret);
	return (ret);
}
