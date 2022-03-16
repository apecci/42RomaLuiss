SRCS =	$(wildcard *.c)

OBJS =	$(SRCS:.c=.o)

NAME = server client

all:	$(NAME)

server:	server.o libft
	gcc -o server server.o -Llibft -lft

client:	client.o libft
	gcc -o client client.o -Llibft -lft

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
