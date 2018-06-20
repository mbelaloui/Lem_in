/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:14:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/14 11:17:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lim_in.h"

void	ft_put_option(t_option *op)
{
	ft_printf("file    %d\n", op->f);
	ft_printf("rooms   %d\n", op->r);
	ft_printf("links   %d\n", op->l);
	ft_printf("map     %d\n", op->m);
}
