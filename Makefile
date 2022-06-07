# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/06/06 22:58:05 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_FILES = so_long.c
LIBFT = includes/libft/libft.a
LIBFT_PATH = includes/libft/
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIBXFLAG_LINUX = -lbsd -lXext -lX11
MINILIBX_LINUX 	= includes/minilibx-linux/libmlx.a

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
	@echo "Preparing Libft"
	@$(MAKE) -s -C $(LIBFT_PATH)
	@echo "Preparing $(NAME)"
	@printf "Compiling -"

$(NAME): $(OBJS)
	@$(CC) -o $@ $^ $(LIBFT) $(MINILIBX_LINUX) $(CFLAGS) $(LIBXFLAG_LINUX)

clean:
	@$(REMOVE) $(OBJS)
	@@$(MAKE) -s clean -C $(LIBFT_PATH)
fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_PATH)

re:	fclean all

git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push
	