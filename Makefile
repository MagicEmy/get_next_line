all:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_again_test.c get_next_line_utils.c -g -fsanitize=address
	./a.out