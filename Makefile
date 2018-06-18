# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 11:37:42 by mbelalou          #+#    #+#              #
#    Updated: 2018/06/15 13:36:14 by mbelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in

FLAGES			= -Wall -Wextra -Werror -c

DIR_DISPLAY		= display
SRC_DISPLAY		= ft_put_file.c ft_put_help.c ft_put_links.c ft_put_option.c\
				  ft_put_room.c ft_put_usage.c
SRCS_DISPLAY	= $(addprefix $(DIR_DISPLAY)/, $(SRC_DISPLAY))

DIR_ERROR_MSG	= error_message
SRC_ERROR_MSG	= ft_ants_error.c ft_links_error.c ft_option_error.c\
				  ft_room_error.c ft_syntax_error.c
SRCS_ERROR_MSG	= $(addprefix $(DIR_ERROR_MSG)/, $(SRC_ERROR_MSG))

DIR_MAP			= map
SRC_MAP			= ft_init_map.c ft_put_map.c ft_resolve_map.c
SRCS_MAP		= $(addprefix $(DIR_MAP)/, $(SRC_MAP))

DIR_PARSING		= parsing
SRC_PARSING		= ft_extract_info_file.c ft_get_nbr_ants.c ft_is_comment.c\
				  ft_extract_options.c ft_get_room.c ft_is_end.c\
				  ft_first_passe.c ft_get_room_graph.c ft_is_start.c\
				  ft_get_links_room_graph.c ft_init_option.c
SRCS_PARSING	= $(addprefix $(DIR_PARSING)/, $(SRC_PARSING))

INC_DIR			= inc/

OBJS_DIR		= bin/

LIBFT_DIR		= libft

LIBFT			= libft.a

SRCS			= exe.c $(SRCS_DISPLAY) $(SRCS_ERROR_MSG) $(SRCS_MAP)\
		$(SRCS_PARSING)

RED				= \033[31m
GREEN			= \033[32m
YELLO			= \033[33m
WHITE			= \033[37m
BIP				= \a

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all				: $(NAME)

$(NAME)			: $(LIBFT) $(OBJS_DIR) $(OBJS)
	@gcc $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) has been successfully created !$(WHITE)."
	@#say "$(NAME) has been successfully created !"

$(OBJS_DIR)%.o	: ./src/%.c
	@echo "$< $(GREEN) compiled $(WHITE)"
	@echo "\033[1A \033[2K \033[A"
	@gcc $(FLAGES) $< -o $@ -I $(INC_DIR)

$(LIBFT)		:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)		:
	@mkdir -p $(OBJS_DIR);
	@mkdir -p $(OBJS_DIR)$(DIR_DISPLAY);
	@mkdir -p $(OBJS_DIR)$(DIR_ERROR_MSG);
	@mkdir -p $(OBJS_DIR)$(DIR_PARSING);
	@mkdir -p $(OBJS_DIR)$(DIR_MAP);
	@#mkdir -p $(OBJS_DIR)/$(DIR_CHECKER);

clean			:
	@make -C $(LIBFT_DIR) clean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the checker binary files$(WHITE)."
	@#say "cleaned the $(NAME) binary files."

fclean			:
	@make -C $(LIBFT_DIR) fclean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the $(NAME) file$(WHITE)."
	@rm -f $(NAME)
	@echo "$(GREEN)the $(NAME) directory is totaly cleaned !!$(WHITE)."
	@#say "the $(NAME) directory is totaly cleaned !"

re				: fclean all

norm 			:
	@norminette | grep -B 1 "Error"

.PHONY : all clean fclean re
