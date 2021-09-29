##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	main.c				\
		src/print_env.c		\
		src/env_mod.c		\
		src/env_mod_unset.c	\
		src/env_search.c	\
		src/prog_exe.c		\
		src/cd_command.c	\
		src/array_management.c\
		src/signal_handle.c\
		src/separator_gestion.c\
		src/split_command.c\
		src/separe_separator.c\
		src/echo_command.c\
		src/print_prompt.c\
		src/init_list_alias.c\
		src/alias_command.c\
		src/separator_of_exec.c\
		src/take_exec_separators.c\
		src/tools_commands.c\
		src/pipe_and_redir_manager.c\
		src/history.c\
		lib/my_putchar.c\
		lib/my_putstr.c\
		lib/my_str_cmp.c\
		lib/my_strlen.c\
		lib/str_to_arr.c\
		lib/my_strcpy.c\
		lib/concat_str.c

TEST=	tests/lib_test.c\
		tests/env_test.c\
		lib/str_to_arr.c\
		lib/my_strlen.c\
		lib/my_str_cmp.c\
		lib/my_putstr.c\
		lib/my_putchar.c\
		src/env_search.c\

OBJ	=	$(SRC:.c=.o)

CFLAGS += -Wextra -Wimplicit -Wall -g3

CPPFLAGS	=	-I./include/

NAME	=	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

tests_run:
	gcc -o unit_tests -lcriterion --coverage $(CPPFLAGS) $(TEST)
	./unit_tests

clean:
	rm -f $(OBJ) unit_tests *.gcno *.gcda
	rm -fr .config/ .history

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
