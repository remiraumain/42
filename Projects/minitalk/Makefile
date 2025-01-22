# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2025/01/22 16:51:59 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minitalk
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

SERVER_SRC =	server.c
CLIENT_SRC =	client.c
SERVER_BONUS_SRC =	server_bonus.c
CLIENT_BONUS_SRC =	client_bonus.c

SERVER_OBJ =	$(SERVER_SRC:.c=.o)
CLIENT_OBJ =	$(CLIENT_SRC:.c=.o)
SERVER_BONUS_OBJ =	$(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ =	$(CLIENT_BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): libft ft_printf server client

bonus: libft ft_printf server_bonus client_bonus

server: $(SERVER_OBJ) libft ft_printf
	$(CC) $(CFLAGS) $(SERVER_OBJ) -Llibft -lft -Lft_printf -lftprintf -o server

client: $(CLIENT_OBJ) libft ft_printf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -Llibft -lft -Lft_printf -lftprintf -o client

server_bonus: $(SERVER_BONUS_OBJ) libft ft_printf
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -Llibft -lft -Lft_printf -lftprintf -o server_bonus

client_bonus: $(CLIENT_BONUS_OBJ) libft ft_printf
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -Llibft -lft -Lft_printf -lftprintf -o client_bonus

libft:
	@$(MAKE) -C libft

ft_printf:
	@$(MAKE) -C ft_printf

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re server client libft ft_printf