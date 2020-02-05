# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 17:08:42 by rlozano           #+#    #+#              #
#    Updated: 2020/02/05 13:12:53 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_aster.c \
			ft_reinit.c \
			ft_int.c \
			ft_itoa_base.c \
			ft_preidth.c \
			ft_type.c \
			ft_printf.c \
			ft_printu.c \
			ft_putstr.c

OBJS	:= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.
RM		= rm -f

all: ${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

%.o: libft/%.c
	${CC} ${CFLAGS} -c $< -o $@
	
${NAME}:${OBJS}
		make -C libft 
		ar rc ${NAME} libft/*.o ${OBJS}

debug:
		$(CC) $(CFLAGS) -g $(SRCS) libft/ft_*.c -I libft

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} libft/*.o *.o

re:		fclean all
.PHONY: all clean fclean re
