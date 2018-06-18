/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:20:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 16:22:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

t_ant	*ft_new_ant(int id, int pos)
{
	t_ant *ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->id = id;
	ret->pos = pos;
	ret->next = NULL;
	return (ret);
}
