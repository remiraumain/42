# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2024/11/18 21:27:45 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		get_next_line.a
CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror

CSRC =		get_next_line.c get_next_line_utils.c

OSRC =		$(CSRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OSRC)
	$(CC) -c $(CFLAGS) $(CSRC)
	ar -rcs $@ $(OSRC)

clean:
	rm -f $(OSRC) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
