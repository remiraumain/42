# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 07:55:28 by rraumain          #+#    #+#              #
#    Updated: 2024/12/19 23:34:59 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c
UTILS_SRC = $(addprefix utils/, cleanups.c error.c map_init.c map_validation.c)
GNL_SRC = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

OBJ := $(SRC:%.c=%.o)
UTILS_OBJ := $(UTILS_SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Wextra -Wall -Werror -g

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): libft ft_printf $(MLX) $(GNL_OBJ) $(OBJ) $(UTILS_OBJ)
	$(CC) $(CCFLAGS) $(GNL_OBJ) $(OBJ) $(UTILS_OBJ) $(MLX_FLAGS) -Llibft -lft -Lft_printf -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

libft:
	@$(MAKE) -C libft

ft_printf:
	@$(MAKE) -C ft_printf

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJ) $(UTILS_OBJ) $(GNL_OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft ft_printf mlx