NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L./minilibx
INCLUDES = -I./src -I./minilibx

SRC = $(shell find src -name "*.c")
OBJS = $(SRC:.c=.o)

MINILIBX = minilibx/libmlx.a

all: $(MINILIBX) $(NAME)

.%c.%o:
	@$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

$(NAME): $(OBJS)
	@echo "Program Linking Started"
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(MINILIBX) -o $(NAME)
	@echo "Program Linked"

$(MINILIBX):
	MAKE -C minilibx 2>/dev/null
norm:
	@norminette $(shell find src -name "*.c")
	@norminette $(shell find src -name "*.h") -R checkForbidden

re: fclean all

clean:
	find . -name "*.o" -delete -print
	make -C minilibx clean

fclean:clean
	rm $(NAME) $(BONUS)
	make -C fclean

.PHONY: fclean clean all re norm
