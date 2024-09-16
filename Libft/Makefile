# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:03:12 by imraoui           #+#    #+#              #
#    Updated: 2023/02/02 17:25:49 by imraoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=			ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				print.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_add_libft.c \

OBJS		=	${SRCS:.c=.o}

SRCS_BONUS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c


OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

.c.o:
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

bonus:			${OBJS} ${OBJS_BONUS}
				ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}

#so:
#				$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS)
#				gcc -nostartfiles -shared -o libft.so $(OBJS)

re:				fclean all

.PHONY:			all bonus clean fclean re

