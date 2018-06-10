/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:35:40 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:36:11 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

BOOL	ft_is_comment(char *str)
{
	if (str)
	{
		if (ft_is_start(str) || ft_is_end(str))
			return (F);
		if (str[0] == '#')
			return (T);
	}
	return (F);
}
