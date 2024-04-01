NAME = philo_bonus
SRCS = *.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLAGS = -g -fsanitize=thread

all: $(NAME)

bonus : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo ready goooo!

clean:
	@rm -rf *.o

fclean:
	@rm -rf $(NAME)

re: fclean all

race: 
	@$(CC) $(CFLAGS) $(RACEFLAGS) $(SRCS) -o philo_race