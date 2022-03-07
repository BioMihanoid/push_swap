NAME = push_swap

FLAGS = -Wall -Wextra -Werror -MD

CC = gcc

SRC = *.c

HEADER = push_swap.h

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	gcc $(SRC) $(FLAGS) -o $(NAME)

%o:	%.c
	gcc $(FLAGS) -c $< -o $@

clean:
		 rm -rf $(OBJ) *.d

fclean:	 clean
		 rm -rf $(NAME) *.d

re:		 fclean all

.PHONY: clean fclean all re