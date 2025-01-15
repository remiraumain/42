# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 07:55:28 by rraumain          #+#    #+#              #
#    Updated: 2025/01/15 10:07:56 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c
UTILS_SRC = $(addprefix utils/, cleanups.c error.c map_init.c map_validation.c map_utils.c check_collectible_path.c)
GNL_SRC = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

OBJ := $(SRC:%.c=%.o)
UTILS_OBJ := $(UTILS_SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
OBJS := $(OBJ) $(UTILS_OBJ) $(GNL_OBJ)

CC = gcc
CCFLAGS = -Wextra -Wall -Werror -g

MLX_DIR = mlx_linux
MLX = $(MLX_DIR)/libmlx.a

LIBS_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -Lft_printf -lftprintf

all: $(NAME)

$(NAME): libft ft_printf $(MLX) $(GNL_OBJ) $(OBJ) $(UTILS_OBJ)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Imlx -Iincludes -O3 -c $< -o $@

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