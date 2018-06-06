/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:46:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/06 19:19:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_H
# define LISTNODE_H

# include "node.h"

typedef struct			s_listnode
{
	t_node				*node;
	struct s_listnode	*next;
}						t_listnode;

#endif
