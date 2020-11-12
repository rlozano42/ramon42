# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 11:44:46 by rlozano           #+#    #+#              #
#    Updated: 2020/11/12 12:32:20 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =  includes/libft/*.c ft_space.c check.c ft_handle.c raycasting.c readmap.c keyorientation.c window.c bmp.c raycasting1.c sprites.c ft_handle2.c raycasting_utils.c raycasting2.c sprites2.c check2.c

SRCGNL = includes/GNL/get_next_line.c includes/GNL/get_next_line_utils.c

SRCCUB =   cub3d.c 

SRCMLX = includes/minilibx

SRCLIBFT = includes/libft

CC = gcc 
RM = rm -f
all: $(NAME)

$(NAME):
	@make -C $(SRCLIBFT)
	@make -C $(SRCMLX)
	${CC} ${SRC}  ${SRCCUB} includes/libft/libft.a  ${SRCGNL} includes/minilibx/libmlx.a  -framework OpenGL -framework AppKit -o $(NAME)
	

debug:
	${CC}  ${SRC} ${SRCCUB}  includes/libft/libft.a ${SRCGNL} includes/minilibx/libmlx.a -g  -framework OpenGL -framework AppKit -o $(NAME)

fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
	@echo "Cleaning Cub3d..."

clean:
	${RM} ${OBJ} ${OBJBONUS}
	@echo "Cleaning hashcode objects..."

re: fclean all

.PHONY: all clean fclean re bonus
