NAME = libftprintf.a

HEADER = ft_printf.h
SRCS =	ft_printf.c  ft_utils.c
CC = gcc
CFLAGS= -Wall -Werror -Wextra
OBJS =	$(SRCS:.c=.o)
$(NAME) : $(HEADER) $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
