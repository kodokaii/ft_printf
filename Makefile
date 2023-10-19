NAME 		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
LIB 		= libft/libft.a
SRC 		= $(wildcard *.c)
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

debug:
	$(eval CFLAGS += -g)
	$(MAKE) all

$(NAME): $(OBJ) $(LIB)
	ar crs $(NAME) $(OBJ) $(LIB)

$(LIB): 
	$(MAKE) -C $$(dirname $@)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	for lib in $$(dirname $(LIB)); do $(MAKE) clean -C $$lib; done
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY:		all debug clean fclean re
