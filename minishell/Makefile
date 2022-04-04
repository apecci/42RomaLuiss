NAME			=	minishell

SRCS			=	minishell.c \
					utils.c utils1.c utils2.c utils3.c utils4.c utils5.c utils6.c utils7.c \
					utils_env.c utils_env2.c utils_env3.c utils_env4.c utils_env5.c \
					utils_sandro.c utils_sandro1.c \
					utils_sig.c \
					utils_token.c utils_token1.c utils_token2.c utils_token3.c \
					utils_exe.c \
					utils_pipe.c utils_pipe1.c \
					utils_red.c \
					utils_fd.c utils_fd1.c \
					utils_builtin.c \
					utils_exit.c \
					utils_file.c \
					utils_arguments.c \
					utils_cd.c \
					utils_echo.c \
					utils_pwd.c \
					utils_export.c \
					utils_unset.c \

					
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -pthread

READLINE_LIB	=	-lreadline -L/goinfre/apecci/.brew/opt/readline/lib

READLINE_INC	=	-I/goinfre/apecci/.brew/opt/readline/include

RM				=	rm -rf

all:		$(NAME)

$(NAME):	
			@echo "\033[0;33mCompilamiento..."
			${CC} ${CFLAGS} ${SRCS} ${READLINE_LIB} ${READLINE_INC} -o ${NAME} 
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