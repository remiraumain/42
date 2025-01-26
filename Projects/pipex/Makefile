# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2025/01/25 18:58:34 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = $(addprefix src/, main.c parse_args.c pipex.c execute.c utils.c)

OBJS = $(SRCS:.c=.o)

LIBS = libft/libft.a
INCLUDES = $(addprefix -I, $(dir $(LIBS))) -Iincludes

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o pipex

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBS):
	@$(MAKE) -C $(dir $@)

clean:
	@$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re