/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lim_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:48:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/06 19:19:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIM_IN_H
# define LIM_IN_H

# include "../libft/inc/libft.h"
# include "listnode.h"
# include "node.h"
# define  SP  ' '

typedef struct			s_map
{
	intmax_t			nbr_ant;
	t_node				*start;
	t_node				*end;
}						t_map;

#endif
