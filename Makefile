# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/06/20 11:02:16 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = includes/libft/libft.a
LIBFT_PATH = includes/libft/

SRCS_FILES = so_long.c initialization.c movements.c get_next_line.c validation.c
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIBXFLAG_LINUX = -lbsd -lXext -lX11
MINILIBX_LINUX = includes/minilibx-linux/libmlx.a
MINILIBX_PATH_				LINUX = includes/minilibx-linux/

LIBXFLAG = -framework OpenGl -framework Cocoa
MINILIBX = includes/minilibx_opengl/libmlx.a
MINILIBX_PATH = includes/minilibx_opengl/

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
	./so_long maps/01_complete.ber
test2:
	./so_long maps/02_no_extension
test3:
	./so_long maps/03_empty.ber
test4:
	./so_long maps/04_left_missing.ber
test5:
	./so_long maps/05_down_missing.ber
test6:
	./so_long maps/06_top_missing.ber
test7:
	./so_long maps/07_right_missing.ber
test8:	
	./so_long maps/08_end_missing.ber
test9:
	./so_long maps/09_items_missing.ber
test10:
	./so_long maps/10_start_missing.ber
test11:
	./so_long maps/11_too_big_map.ber
test12:	
	./so_long maps/12_map_not_rectangle.ber