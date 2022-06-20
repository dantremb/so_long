# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/06/19 23:44:32 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = includes/libft/libft.a
LIBFT_PATH = includes/libft/

SRCS_FILES = so_long.c initialization.c movements.c get_next_line.c validation.c
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIBXFLAG= -lbsd -lXext -lX11
MINILIBX	= includes/minilibx-linux/libmlx.a
MINILIBX_PATH	= includes/minilibx-linux/
LIBXFLAG_MAC = -framework OpenGl -framework Cocoa
MINILIBX_MAC 	= includes/minilibx_opengl/libmlx.a
MINILIBX_PATH_MAC 	= includes/minilibx_opengl/

AR = ar
CC = gcc


ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g


REMOVE = rm -rf
COMMIT = $(shell date "+%d %B %T")

OBJS= $(SRCS:%.c=%.o)
%.o: %.c
	@printf "-"
	@$(CC) $(CFLAGS) -o $@ -c $<

all: init $(NAME)
	@echo "> Done!."
	@echo "$(NAME) Compiled!"

init:
	@echo "Preparing Minilibx"
	@$(MAKE) -s -C $(MINILIBX_PATH)
	@echo "Preparing Libft"
	@$(MAKE) -s -C $(LIBFT_PATH)
	@echo "Preparing $(NAME)"
	@printf "Compiling -"

$(NAME): $(OBJS)
	@$(CC) -o $@ $^ $(LIBFT) $(MINILIBX) $(CFLAGS) $(LIBXFLAG)

clean:
	@$(REMOVE) $(OBJS)
	@$(MAKE) -s clean -C $(LIBFT_PATH)
	@$(MAKE) -s clean -C $(MINILIBX_PATH)
fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_PATH)
	@$(MAKE) -s clean -C $(MINILIBX_PATH)

re:	fclean all

git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

test1:
	./so_long maps/1_complete.ber
test2:
	./so_long maps/2_no_extension
test3:
	./so_long maps/3_empty.ber
test4:
	./so_long maps/4_left_missing.ber
test5:
	./so_long maps/5_down_missing.ber
test6:
	./so_long maps/6_top_missing.ber
test7:
	./so_long maps/7_right_missing.ber
test8:	
	./so_long maps/8_end_missing.ber
test9:
	./so_long maps/9_items_missing.ber
test10:
	./so_long maps/10_start_missing.ber
test11:
	./so_long maps/11_too_big_map.ber
test12:	
	./so_long maps/12_map_not_rectangle.ber