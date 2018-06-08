/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 03:20:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/11 14:46:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/char.h"

BOOL	ft_isblank(const char c)
{
	if ((c == 9) || (c == ' '))
		return (T);
	return (F);
}