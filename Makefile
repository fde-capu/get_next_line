all:
	clang -g -Wall -Werror -Wextra -D BUFFER_SIZE=1000000 \
		main.c get_next_line.c get_next_line_utils.c
	./a.out
bonus:
	clang -g -Wall -Werror -Wextra -D BUFFER_SIZE=1000000 \
		main.c get_next_line_bonus.c get_next_line_utils_bonus.c
	./a.out
