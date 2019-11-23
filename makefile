# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 09:31:09 by gconde-m          #+#    #+#              #
#    Updated: 2019/11/22 19:19:56 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=	ft_strlen.c \
		ft_atoi.c \
		ft_strlcat.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_strlcpy.c \
		ft_isprint.c \
	   	ft_strnstr.c \
	    ft_strncmp.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c

DINCLUDE	= includes

INCLUDES	= ${DINCLUDE}/ft.h

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC 			= gcc

CFLAGS		 = -Wall -Wextra -Werror -I. -c

RM			 = rm -f

.c.o:		${INCLUDES}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}	
all:	${NAME}
clean:
		${RM} ${OBJS}
fclean:		clean
		${RM} ${NAME}
re:			fclean all

.PHONY:	all clean fclean re
