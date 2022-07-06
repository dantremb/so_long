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

# Nom du Projet
NAME = so_long

# Flags
AR = ar
CC = gcc
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

# Includes
LIBFT = includes/libft/libft.a
LIBFT_PATH = includes/libft/

LIBXFLAG = -lbsd -lXext -lX11
MINILIBX = includes/minilibx-linux/libmlx.a
MINILIBX_PATH = includes/minilibx-linux/

LIBXFLAG_MAC = -framework OpenGl -framework Cocoa
MINILIBX_MAC = includes/minilibx_opengl/libmlx.a
MINILIBX_PATH_MAC = includes/minilibx_opengl/

# Sources files
S = srcs/
SRCS_FILES = so_long.c \
			initialization.c \
			movements.c \
			get_next_line.c \
			validation.c 
SRCS = $(addprefix $S, $(SRCS_FILES))

# Objects conversion
O = objs/
OBJS= $(SRCS:$S%=$O%.o)
$O%.o: $S%
	@printf "$R■$W"
	@$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: signature init $(NAME)
	@echo "$G\n$(NAME) Compiled!$W"

# Initialise librairies and making objs folder
init:
	@mkdir -p $O
	@echo "$GLibrary's initialization$W"
	@echo "Creating Minilibx"
	@$(MAKE) -s -C $(MINILIBX_PATH)
	@$(MAKE) -s -C $(LIBFT_PATH)
	@printf "$CCreating $(NAME)\n$W"

# Creating  executable
$(NAME): $(OBJS)
	@$(CC) -o $@ $^ $(LIBFT) $(MINILIBX) $(CFLAGS) $(LIBXFLAG)

# Cleaning
REMOVE = rm -rf

clean:
	@$(REMOVE) $O
	@$(MAKE) -s clean -C $(LIBFT_PATH)

fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_PATH)

re:	fclean all

# Utilities
COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

signature:
	@echo "\n$G+---+---+---+---+---+---+---+---+"
	@echo "$G|$C	$(NAME) by Dantremb	$G|"
	@echo "$G+---+---+---+---+---+---+---+---+"

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
	