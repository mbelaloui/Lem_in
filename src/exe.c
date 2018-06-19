/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:55:53 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 17:56:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lim_in.h"

static void	read_map(t_option op)
{
	t_charlist	*file;
	t_charlist	*links;
	t_map		map;
	t_nodelist	*listnodes;

	ft_init_map(&map);
	file = ft_first_passe();
	if (op.f)
		ft_put_file(file);
	listnodes = ft_extract_info_file(file, &map, &links);
	if (!links)
		ft_links_error(ERROR_NO_LINKS, "");
	if (op.r)
		ft_put_room(listnodes);
	else if (op.l)
		ft_put_links(links);
	else if (op.m)
		ft_put_map(&map);
	else
		ft_resolve_map(map, listnodes, op);
	ft_clear_list_nodelist(&listnodes);
	ft_dell_list_charlist(&file);
}

int			main(int argc, char **argv)
{
	char		*param;
	t_option	op;
	int			c;

	ft_init_option(&op);
	param = NULL;
	param = ft_mat_to_str(argv, 1);
	c = ft_extract_options(param, &op);
	ft_strdel(&param);
	if (op.u)
		ft_put_usage();
	else if (op.h)
		ft_put_help();
	else if (c >= 0 || !argc)
		read_map(op);
	else
		ft_option_error();
	return (0);
}
