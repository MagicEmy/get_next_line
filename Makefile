NAME	:=	gnl
SRC		:=	main.c \
			get_next_line.c \
			get_next_line_utils.c

CC		:= 	gcc
CFLAGS	:= -Wall -Wextra -Werror # -g -fsanitize=address
CBUFF	:= -D BUFFER_SIZE=300

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CBUFF) -o $(NAME) $(SRC)
# ./$(NAME)


# run: $(NAME)
# 	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# all:
# 	cc -Wall -Wextra -Werror -D BUFFER_SIZE=3000000 main.c get_next_line.c get_next_line_utils.c -g -fsanitize=address
# 		./a.out
