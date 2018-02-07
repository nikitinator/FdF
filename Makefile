# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 17:36:11 by snikitin          #+#    #+#              #
#    Updated: 2018/02/07 21:01:02 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf         

SRC_DIR := ./srcs/
OBJ_DIR := ./obj/
INC_DIR := ./includes/
LIB_DIR := ./lib/

SRC :=	main.c \
		scrn_upd.c\
		get_pixel_arr.c\
		get_point_arr.c\
		mov_x.c mov_y.c mov_z.c\
		rotate_x.c rotate_y.c rotate_z.c\
		init_rot_mat.c\
		transform.c rotate.c scale.c\
		drw_line_bras.c\
		mult_matr.c\
		add_color.c\
		sub_color.c\
		apply.c\
		exit_fdf.c\
		change_clr_val.c\
		reset_color.c\
		get_list.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = $(INC_DIR)fdf.h 

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=    $(LIB_DIR)libft/
LIBFT_INC :=    $(LIBFT_DIR)/
LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)

MLX = $(LIB_DIR)mlx/libmlx.a
MLX_DIR = $(LIB_DIR)mlx/
MLX_INC = $(LIB_DIR)mlx/
MLX_FLAGS = -lmlx -L $(MLX_INC) -framework OpenGl -framework AppKit

CC_FLAGS := -Wall -Wextra -Werror -O3
LINK_FLAGS := $(LIBFT_FLAGS) $(MLX_FLAGS)
HEADER_FLAGS := -I $(LIBFT_INC) -I $(MLX_DIR) -I $(INC_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ) $(INC) 
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re
