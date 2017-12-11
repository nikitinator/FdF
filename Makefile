# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 12:43:36 by amelihov          #+#    #+#              #
#    Updated: 2017/12/11 13:39:06 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang 

CFLAGS = -Wall -Wextra -Werror

FRWORKS = -framework Opengl -framework AppKit

INC_DIR = ./includes/
SRC_DIR = ./srcs/
LIB_DIR = ./libft/
MLX_DIR = ./minilibx_macos/


_INC = fdf.h
_SRC = main.c

INC = $(_INC:%.h=$(INC_DIR)%.h)
SRC = $(_SRC:%.c=$(SRC_DIR)%.c)
OBJ = $(_SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx\
		$(FRWORKS)

%.o: $(SRC_DIR)%.c $(INC) 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all
