all:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=300 \
	main.c get_next_line.c get_next_line_utils.c -g
		./a.out
	
#cc -Wall -Wextra -Werror -D \
BUFFER_SIZE=2 main.c get_next_line.c get_next_line_utils.c -g -fsanitize=address
#	./a.out