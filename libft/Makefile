# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apecci <alessandro.pecci17@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 09:13:19 by apecci            #+#    #+#              #
#    Updated: 2021/01/13 09:13:22 by apecci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_strchr.c ft_isalnum.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isdigit.c ft_isalpha.c ft_atoi.c ft_memcmp.c ft_memmove.c ft_memset.c ft_memcpy.c ft_bzero.c ft_isascii.c ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strrchr.c ft_memchr.c ft_strnstr.c ft_memccpy.c ft_itoa.c ft_strlcat.c ft_strdup.c ft_calloc.c ft_strmapi.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_lstmap.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstnew.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
