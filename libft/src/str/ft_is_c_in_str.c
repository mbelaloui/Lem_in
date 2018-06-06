/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 09:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 12:58:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

BOOL		ft_is_c_in_str(const char c, const char *str)
{
	if (!str || !c)
		return (F);
	while (*str)
	{
		if (*str++ == c)
			return (T);
	}
	return (F);
}
