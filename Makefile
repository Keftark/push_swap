# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:58:06 by cpothin           #+#    #+#              #
#    Updated: 2023/06/30 09:46:48 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

MAKEFLAGS += --silent
AR = ar rcs
RM = rm -rf
CC =	gcc
INCLUDE = -I include
CFLAGS	= -Wall -Wextra -Werror -g3

FILES = push_swap \
	swapper \
	commons \
	display \
	check_errors \
	ft_strtol \
	free_all \
	fill_data_struct \
	sort_list \
	sort_big \
	move_numbers \
	ft_split \
	
SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) ${OBJS} -o $(NAME)
		@echo "\n\033[32mCompiled!\033[0m\n"

all:	${NAME}

clean:
	@$(RM) $(OBJS_DIR)
	@echo "\n\033[0;31mCleaned!\033[0m\n"


fclean:
	@$(RM) $(NAME)
	@$(MAKE) clean

re:	fclean all

.PHONY: all clean fclean re
