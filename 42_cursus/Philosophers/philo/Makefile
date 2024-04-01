NAME = philo
SRCS = *.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLAGS = -g -fsanitize=thread

all: $(NAME)

$(NAME): $(SRCS) 
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo ready goooo!

clean:
	@rm -rf *.o

fclean:
	@rm -rf $(NAME)

re: fclean all

race: 
	@$(CC) $(CFLAGS) $(RACEFLAGS) $(SRCS) -o philo_race