NAME = push_swap

FLAGS = -Wall -Wextra -Werror -MD

CC = gcc

SRC = 	big_sort.c		\
		mini_sort.c		\
		operation1.c	\
		operation2.c	\
		operation3.c	\
		push_swap.c		\
		split.c			\
		utils1.c		\
		utils2.c		\
		utils3.c		\
		utils4.c		\
		utils5.c		\
		validation.c	\

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