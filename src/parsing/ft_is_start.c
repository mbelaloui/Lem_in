/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:34:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/14 16:46:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

BOOL	ft_is_start(char *str)
{
	char *start;

	start = "##start";
	if (!ft_strcmp(str, start))
		return (T);
	return (F);
}
