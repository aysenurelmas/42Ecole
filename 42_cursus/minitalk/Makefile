NAME	:=
SERVER	:= server
CLIENT	:= client

CLIENT_SRC	:= client.c
SERVER_SRC	:= server.c
UTILS_SRC	:= ft_utils.c

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra

$(NAME): $(all)

all: $(CLIENT) $(SERVER)

$(CLIENT): client.o 
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

$(SERVER): server.o
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(SERVER) $(CLIENT)

re:	fclean all

.PHONY: all clean fclean re 
