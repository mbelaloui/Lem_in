/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lim_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:48:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:35:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIM_IN_H
# define LIM_IN_H

# include "../libft/inc/nodelist.h"

# define SP								' '

# define ERROR_OVERFLOW_NBR_ANTS		-5
# define ERROR_FORMAT_NBR_ANTS			-4
# define ERROR_NEGATIVE_VAL_NBR_ANTS	-3
# define ERROR_NULL_VAL_NBR_ANTS		-2
# define ERROR_DUPLICATS_VAL_ANTS		-1

# define ERROR_EMPTY_FILE				0
# define ERROR_NO_START					1
# define ERROR_NO_END					2
# define ERROR_EMPTY_LINE				3
# define ERROR_DUPLICAT_START_ROOM		4
# define ERROR_DUPLICAT_END_ROOM		5
# define ERROR_FORMAT_LINE				6
# define ERROR_NAME_ROOM_FORMAT			7
# define ERROR_COORDINATES_ROOM_FORMAT	8
# define ERROR_COORDINATES_ROOM_EXIST	9
# define ERROR_FORMAT_LINK				10
# define ERROR_LINK_NAME_ROOM			11
# define ERROR_LINK_ROOM_ROOM			12
# define ERROR_NO_START_END_ROOM		13
# define ERROR_NO_LINKS					14
# define ERROR_NO_START_ROOM_DECLARED	15
# define ERROR_NO_END_ROOM_DECLARED		16
# define ERROR_NO_ENOUGH_DATA			17
# define ERROR_NO_PATH					18

typedef struct		s_map
{
	intmax_t		nbr_ants;
	int				start;
	int				end;
}					t_map;

typedef struct		s_option
{
	int				b;
	int				f;
	int				h;
	int				l;
	int				m;
	int				r;
	int				u;
}					t_option;

typedef struct		s_ant
{
	int				id;
	int				pos;
	struct s_ant	*next;
}					t_ant;

void				ft_put_map(t_map *map);
void				ft_init_map(t_map *map);

void				ft_syntax_error(int error);
void				ft_ants_error(int error);
void				ft_room_error(int error, char *line);
void				ft_links_error(int error, char *line);
BOOL				ft_is_start(char *str);
BOOL				ft_is_end(char *str);
BOOL				ft_is_comment(char *str);

t_charlist			*ft_first_passe(void);
intmax_t			ft_get_nbr_ants(t_charlist *line);
t_node				*ft_get_room(char *str, int id_room);
t_charlist			*ft_get_room_graph(t_map *map, t_charlist*line,
		t_nodelist **lstnodes);
void				ft_get_links_room_graph(t_charlist *links,
		t_nodelist *listnodes);
t_nodelist			*ft_extract_info_file(t_charlist *file, t_map *map,
		t_charlist **links);
void				ft_init_option(t_option *op);

void				ft_option_error(void);

BOOL				ft_extract_options(char *param, t_option *options);
void				ft_put_links(t_charlist *links);
void				ft_put_file(t_charlist *file);
void				ft_put_room(t_nodelist *listnodes);
void				ft_put_option(t_option *op);
void				ft_put_help(void);
void				ft_put_usage(void);

void				ft_resolve_map(t_map map, t_nodelist *nodelist,
		t_option op);
void				ft_erro_map(int error);

t_ant				*ft_new_ant(int id, int pos);
BOOL				ft_add_end_antlist(int id, int pos, t_ant **list);
BOOL				ft_is_empty_antlist(const t_ant *list);
void				ft_put_ant(const t_ant *list, t_nodelist *listnode);
BOOL				ft_dell_list_antlist(t_ant **to_free);
t_ant				*ft_init_ants(intmax_t nbr_ants, intmax_t id_room);
BOOL				ft_dell_bgn_ant(t_ant **list);

void				ft_put_best_path(t_int_list *path, t_nodelist *listnode);
int					ft_move_ant(t_ant *ant, t_int_list *path,
		t_nodelist *listnode, t_map map);
void				ft_send_ants(t_ant *ants, t_int_list *path,
		t_nodelist *listnode, t_map map);
#endif
