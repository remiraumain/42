# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2024/11/04 22:04:10 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a
CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror

CSRC =		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c		\
			ft_putptr.c ft_puthex.c ft_selector.c

OSRC =		$(CSRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OSRC)
	$(CC) -c $(CFLAGS) $(CSRC)
	ar -rcs $@ $(OSRC)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re