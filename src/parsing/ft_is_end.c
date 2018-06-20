/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:35:06 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:35:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

BOOL	ft_is_end(char *str)
{
	char *start;

	start = "##end";
	if (!ft_strcmp(str, start))
		return (T);
	return (F);
}
