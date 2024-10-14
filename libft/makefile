NAME := 	libft.a
CFLAGS := 	-Wall -Wextra -Werror
SRC :=		ft_atoi.c ft_bzero.c ft_isalnum.c		\
			ft_isalpha.c ft_isascii.c ft_isdigit.c	\
			ft_isprint.c ft_memcpy.c ft_memset.c	\
			ft_strlen.c
OBJ :=		$(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	cc $(CFLAGS) $^ -c
	ar r $@ $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all