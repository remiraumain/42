# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 21:26:30 by rraumain          #+#    #+#              #
#    Updated: 2024/11/18 20:53:36 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		get_next_line.a
CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror

CSRC =		get_next_line.c get_next_line_utils.c
CBONUS =	get_next_line_bonus.c get_next_line_utils_bonus.c

OSRC =		$(CSRC:.c=.o)
OBONUS =	$(CBONUS:.c=.o)

all: $(NAME)
	
$(NAME): $(OSRC)
	$(CC) -c $(CFLAGS) $(CSRC)
	ar -rcs $@ $(OSRC)

bonus:	$(OBONUS)
	$(CC) -c $(CFLAGS) $(CBONUS)
	ar -rcs $(NAME) $(OBONUS)

clean:
	rm -f $(OSRC) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re