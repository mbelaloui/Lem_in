/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_bgn_ant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:50:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 20:51:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

BOOL	ft_dell_bgn_ant(t_ant **list)
{
	t_ant	*to_free;

	if ((*list) == NULL)
		return (F);
	to_free = *list;
	if (!(*list)->next)
		*list = NULL;
	else
		*list = (*list)->next;
	free(to_free);
	return (T);
}
