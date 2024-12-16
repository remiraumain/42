# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2024/12/16 16:38:47 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INCLUDE =	-I/libft -I/operations -I/utils

S_LIBFT =	libft/ft_atoi.c libft/ft_split.c libft/ft_strdup.c					\
			libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c			\
			libft/ft_strlen.c libft/ft_substr.c
S_OP =		operations/pa.c operations/pb.c operations/ra.c operations/rra.c	\
			operations/sa.c
S_UTILS =	utils/parse.c utils/sort.c utils/stack_one.c utils/stack_two.c
S_ROOT =	parse.c push_swap.c sort.c

OSRC =		$(S_LIBFT:.c=.o) $(S_OP:.c=.o) $(S_UTILS:.c=.o) $(S_ROOT:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OSRC) $(INCLUDE)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re