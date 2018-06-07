/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:02:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/07 11:24:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lim_in.h"

BOOL	is_start(char *str)
{
	char *start;

	start = "##start";
	if (!ft_strcmp(str, start))
		return (T);
	return (F);
}

BOOL	is_end(char *str)
{
	char *start;

	start = "##end";
	if (!ft_strcmp(str, start))
		return (T);
	return (F);
}

BOOL	is_comment(char *str)
{
	if (str)
	{	
		if (is_start(str) || is_end(str))
			return (F);
		if (str[0] == '#')
			return (T);
	}
	return (F);
}

/*
** first passe read the file and ignor the commants 
** return a linked list of line <char *>
*/

t_charlist	*first_passe()
{
	t_charlist *ret;
	char *line;

	line = NULL;
	ret = NULL;
	while (get_next_line(0, &line))
	{
		if (!is_comment(line))
			ft_add_charlist(line, &ret);
		ft_strdel(&line);
	}
	return (ret);
}

void	read_map()
{
	t_charlist *file;

	file = first_passe();
	ft_printf("\n/ *********************************************** \\ \n");
	ft_put_list_charlist(file);
	ft_dell_list_charlist(&file);
}

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	read_map();
	return (0);
}
