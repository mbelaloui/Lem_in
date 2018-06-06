/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:38:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/06 17:01:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "lim_in.h"

typedef struct			s_node
{
	int					id;
	int					x;
	int					y;
	int					stats;
	char				*name;
	t_int_list			*list_neighbors;
}						t_node;

#endif
