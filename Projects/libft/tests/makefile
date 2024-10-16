NAME := test

SRCDIR := .
LIBDIR := ..
TESTYDIR := ../../../Utils/testy
OBJDIR := obj

TEST_SRCS := $(SRCDIR)/test_ft_strlen.c $(SRCDIR)/test_ft_isalpha.c					\
			$(SRCDIR)/test_ft_isdigit.c $(SRCDIR)/test_ft_tolower.c					\
			$(SRCDIR)/test_ft_toupper.c $(SRCDIR)/test_ft_isalnum.c					\
			$(SRCDIR)/test_ft_isascii.c $(SRCDIR)/test_ft_atoi.c

TESTY_SRCS := $(TESTYDIR)/assertions.c $(TESTYDIR)/test_macros.c

LIB_SRCS := $(LIBDIR)/ft_strlen.c $(LIBDIR)/ft_atoi.c $(LIBDIR)/ft_bzero.c 			\
            $(LIBDIR)/ft_isalnum.c $(LIBDIR)/ft_isalpha.c $(LIBDIR)/ft_isascii.c	\
            $(LIBDIR)/ft_isdigit.c $(LIBDIR)/ft_isprint.c $(LIBDIR)/ft_memcpy.c 	\
            $(LIBDIR)/ft_memset.c $(LIBDIR)/ft_tolower.c $(LIBDIR)/ft_toupper.c

SRCS := $(TEST_SRCS) $(LIB_SRCS) $(TESTY_SRCS)

OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCS)))

CC := gcc
CFLAGS := -Wall -Wextra -Werror

INCLUDES := -I$(TESTYDIR) -I$(LIBDIR) -I$(SRCDIR)

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o $(NAME)

$(OBJDIR)/%.o:
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -g -c $(filter %/$*.c, $(SRCS)) -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all