NAME		=	philo

SRCS		=	philo.c \
				utils.c \
				ft_atoi.c \
				init.c \
				routine.c \
				close.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

LIBS		=	-lpthread

RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\033[0;33mCompilamiento..."
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
			@echo "\033[0m"

clean:
			@echo "\033[0;31mPulimiento..."
			$(RM) $(OBJS)
			@echo "\033[0m"

fclean:		clean
			@echo "\033[0;31mRimozionamiento..."
			$(RM) $(NAME)
			@echo "\033[0m"

re:			fclean $(NAME)

.PHONY:	all clean fclean re
