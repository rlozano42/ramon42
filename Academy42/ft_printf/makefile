# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlozano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 18:37:57 by rlozano           #+#    #+#              #
#    Updated: 2020/01/15 18:43:16 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES= ./

SRCS = *.c

OBJS: ${SRCS:.c=.o}

NAME = libftprintf.a

all: $(NAME)

$(NAME) = $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRCS)
   ar -rcs $(NAME) $(OBJS)	

debug:
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRCS) -g	

clean:
	-@ rm -f *.o

fclean: clean
	-@ rm $(NAME)

re: fclean all
.PHONY: clean fclean re all
