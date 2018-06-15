/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:58:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/15 13:34:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

static BOOL	ft_is_option(const char option)
{
	if (option == 'f' || option == 'r' || option == 'l' || option == 'm'
			|| option == 'u' || option == 'h')
		return (T);
	return (F);
}

static void	ft_set_options(char c, t_option *options)
{
	if (c == 'f')
		options->f = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == 'l')
		options->l = 1;
	else if (c == 'm')
		options->m = 1;
	else if (c == 'h')
		options->h = 1;
	else if (c == 'u')
		options->u = 1;
}

BOOL		ft_extract_options(char *param, t_option *options)
{
	int index;

	index = 0;
	while (param[index])
	{
		if (param[index] == '-')
		{
			index++;
			if (ft_is_option(param[index]) && (param[index + 1] == ' '
						|| !ft_isalpha(param[index + 1])))
				ft_set_options(param[index], options);
			else
				return (-1);
		}
		index++;
	}
	return (index);
}
