# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2025/01/25 07:30:25 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_BONUS_SRC = server_bonus.c
CLIENT_BONUS_SRC = client_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

LIBS = libft/libft.a ft_printf/libftprintf.a
INCLUDES = $(addprefix -I, $(dir $(LIBS)))

all: $(NAME)

$(NAME): server client

bonus: server_bonus client_bonus

server: $(SERVER_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -Llibft -lft -Lft_printf -lftprintf -o server

client: $(CLIENT_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -Llibft -lft -Lft_printf -lftprintf -o client

server_bonus: $(SERVER_BONUS_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -Llibft -lft -Lft_printf -lftprintf -o server_bonus

client_bonus: $(CLIENT_BONUS_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -Llibft -lft -Lft_printf -lftprintf -o client_bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBS):
	@$(MAKE) -C $(dir $@)

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re