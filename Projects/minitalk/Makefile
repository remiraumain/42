# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2024/12/17 19:20:32 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minitalk
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

SERVER_SRC =	server.c
CLIENT_SRC =	client.c

SERVER_OBJ =	$(SERVER_SRC:.c=.o)
CLIENT_OBJ =	$(CLIENT_SRC:.c=.o)

all: $(NAME)

$(NAME): libft ft_printf server client

server: $(SERVER_OBJ) libft ft_printf
	$(CC) $(CFLAGS) $(SERVER_OBJ) -Llibft -lft -Lft_printf -lftprintf -o server

client: $(CLIENT_OBJ) libft ft_printf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -Llibft -lft -Lft_printf -lftprintf -o client

libft:
	@$(MAKE) -C libft

ft_printf:
	@$(MAKE) -C ft_printf

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	rm -f server client

re: fclean all

.PHONY: all clean fclean re server client libft ft_printf