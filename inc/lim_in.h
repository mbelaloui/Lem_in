/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lim_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:48:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/10 20:48:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIM_IN_H
# define LIM_IN_H

# include "../libft/inc/nodelist.h"
//# include "nodelist.h"
//# include "node.h"
# define  SP  ' '

#define ERROR_COORDINATES_ROOM_EXIST	7
#define ERROR_COORDINATES_ROOM_FORMAT	6

#define ERROR_FORMAT_LINK_NAME	7
#define ERROR_FORMAT_LINK			6
#define ERROR_NAME_ROOM_EXISTS	5			
#define ERROR_NAME_ROOM_FORMAT	4			
#define ERROR_EMPTY_FILE			3			
#define ERROR_START_FORMAT			2		// il y a deux	
#define ERROR_END_FORMAT			1		// il y a deeux
#define ERROR_EMPTY_LINE			0
#define ERROR_FORMAT					-1
#define ERROR_VAL						-2
#define ERROR_DUPLICATS_VAL_ANT	-3
#define ERROR_NO_START				-4		// il y a deux	
#define ERROR_NO_END					-5		// il y a deeux
#
typedef struct	s_map
{
	intmax_t	nbr_ants;
	int			start;
	int			end;
}				t_map;

void			ft_put_map(t_map *map);
void			ft_init_map(t_map *map);

void			ft_syntax_error(int error);
void			ft_ants_error(int error);
void			ft_room_error(int error);
void			ft_links_error(int error);
BOOL			ft_is_start(char *str);
BOOL			ft_is_end(char *str);
BOOL			ft_is_comment(char *str);

t_charlist		*ft_first_passe(void);
intmax_t		ft_get_nbr_ants(t_charlist *line);
t_node			*ft_get_room(char *str, int id_room);
t_charlist		*ft_get_room_graph(t_map *map, t_charlist*line,
		t_nodelist **lstnodes);
void			ft_get_links_room_graph(t_charlist *links,
		t_nodelist *listnodes);

/*t_node		*ft_new_node(int id, char *name, intmax_t x, intmax_t y);
void 			ft_put_map(t_map *map);
void    ft_put_node(t_node * node);
BOOL    is_start(char *str);
BOOL    is_end(char *str);
BOOL    is_comment(char *str);
BOOL    ft_isnumerique(char *str);
BOOL    ft_get_nbr_ant(t_map *map);
BOOL    is_good_format_room_info(char *str);
t_listnode              *ft_new_listnode(t_node *node);
BOOL    ft_add_end_list_listnode(t_node *node, t_listnode **list);
void    ft_put_list_listnode(t_listnode *list);
BOOL    ft_is_empty_listnode(t_listnode *list);
BOOL    ft_is_in_listcode(char *nom, t_listnode *list);
//BOOL    ft_get_room(t_map *map);
void    ft_init_map(t_map *map);
void    read_map();
*/



#endif
