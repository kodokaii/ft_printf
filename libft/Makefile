NAME 		= libft.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
SRC 		= $(wildcard *.c)
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

debug:
	$(eval CFLAGS += -g)
	$(MAKE) all

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all debug clean fclean re
