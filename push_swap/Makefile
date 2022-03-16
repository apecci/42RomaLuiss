NAME_PUSH	= push_swap
NAME_CHECKER = checker

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

PUSH_SRCS =	algorithm.c     \
            lis.c       \
            get_next_line.c \
            move.c      \
            move2.c     \
            split_utils.c       \
            trap.c      \
            trap1.c     \
            utils1.c    \
            utils2.c    \
            utils3.c    \
            utils4.c    \
            utils5.c    \
			small.c		\
            main.c   \
            free.c

CHECKER_SRCS =	   errors_checker.c     \
            get_next_line.c \
            move_checker.c      \
			checker_utils.c		\
            move_checker2.c     \
            move_checker3.c     \
            split_utils.c       \
			utils1.c    		\
            utils2.c    		\
            utils3.c    		\
            checker.c      		


PUSH_OBJS	= ${PUSH_SRCS:.c=.o}

CHECKER_OBJS	= ${CHECKER_SRCS:.c=.o}

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

all: 		checker push_swap
			@(echo "\033[32m===  PUSH_SWAP AND CHECKER PROJECT COMPILED  ===\033[0m")

push_swap:  ${PUSH_OBJS}
			$(CC) ${CFLAGS} -o ${NAME_PUSH} ${PUSH_OBJS}
			@(echo "\033[32m===  PUSH_SWAP PROJECT COMPILED  ===\033[0m")

checker:  	${CHECKER_OBJS}
			$(CC) ${CFLAGS} ${CHECKER_OBJS} -o ${NAME_CHECKER}
			@(echo "\033[32m===  CHECKER PROJECT COMPILED  ===\033[0m")

clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME_PUSH) $(NAME_CHECKER)
			@echo "\033[33m=== PROJECT CLEANED ===\033[0m"

re: fclean all

.PHONY: all clean fclean re push_swap checker libft