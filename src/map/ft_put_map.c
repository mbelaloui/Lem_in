/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:53:54 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 19:54:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void    ft_put_map(t_map *map)
{
	ft_printf("nbr of ants %d \n", map->nbr_ants);
	ft_printf("id of starting room %d \n", map->start);
	ft_printf("id of ending room %d \n", map->end);
}
