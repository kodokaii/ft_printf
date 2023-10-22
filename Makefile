NAME 		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
LIB 		= libft/libft.a
SRC 		= ft_check.c\
			  ft_hexa.c\
			  ft_integer.c\
			  ft_option.c\
			  ft_parsing.c\
			  ft_pointer.c\
			  ft_printf.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

test: $(NAME)
	gcc main.c $(NAME)

debug:
	$(eval CFLAGS += -g)
	$(MAKE) all

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rs $(NAME) $(OBJ)

$(LIB): 
	$(MAKE) -C $$(dirname $@)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $$(dirname $(LIB));
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY:		all debug clean fclean re
