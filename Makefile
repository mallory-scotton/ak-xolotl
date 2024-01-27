##
## EPITECH PROJECT, 2024
## ak-xolotl
## File description:
## Makefile
##

CC		=		gcc

NAME	=		my_rpg

SRC		=		source/*.c \
				source/shared/char/*.c \
				source/shared/strings/*.c \
				source/shared/memory/*.c \
				source/shared/numbers/*.c \
				source/ressources/*.c

LIB		=		-lcsfml-system \
				-lcsfml-window \
				-lcsfml-graphics \
				-lcsfml-network \
				-lcsfml-audio \
				-lm

FLAG	=		-Wall \
				-Wextra \
				-g \
				-g3 \
				-Iinclude

TSRC	=		tests/*.c

TLIB	=		-lcriterion

TFLAG	=		--coverage

FIND	=		find -type f -iname

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(LIB) $(FLAG)

all: $(NAME)

clean:
	$(FIND) "*.o" -delete
	$(FIND) "*.a" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(CC) -o unit_tests $(SRC) $(TSRC) $(TLIB) $(LIB) $(FLAG) $(TFLAG)
	./unit_tests && gcovr -e tests && gcovr -e tests -b

tests_clean:
	$(FIND) "*.gcno" -delete
	$(FIND) "*.gcda" -delete
	$(FIND) "*.css" -delete
	$(FIND) "*.html" -delete

tests_fclean: tests_clean
	rm -f unit_tests

tests_re: tests_fclean tests_run
