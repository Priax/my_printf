##
## Priax PROJECT, 2025
## Makefile
## File description:
## Makefile for C
##

NAME = my_printf

SRC =	my_printf.c \
		flags.c \
		utilitary_functions.c \
		main.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror -pedantic -g3

ANSIFLAG = -ansi

LIBFLAGS = -lm

FLAG_VAL = --tool=memcheck --leak-check=yes --show-reachable=yes

FLAG_VAL2 = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

$(NAME): $(SRC)
	@gcc $(CFLAGS) $(LIBFLAGS) -o $@ $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

exec: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	find . -type f \( -name "*~" -o \( -name "*#" -a -name "#*" \) \) -delete
	rm -f coding-style-reports.log

re: fclean all

style: fclean
	coding-style . .
	cat coding-style-reports.log

valgrind: exec
	valgrind $(FLAG_VAL) $(FLAG_VAL2) ./$(NAME)

push:
	@echo "Usage: make push -m \"message\""
	@exit 1

push-%:
	@(find . -type f -name "#.#" -delete -o -name "*~" -delete)
	@(git add .)
	@(git commit -m "$*")
	@(git push)

.PHONY: all clean fclean re style exec valgrind
