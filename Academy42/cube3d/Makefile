# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 11:44:46 by rlozano           #+#    #+#              #
#    Updated: 2020/10/25 12:47:21 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

SRC =  includes/libft/*.c ft_space.c check.c ft_handle.c

SRCGNL = includes/GNL/get_next_line.c includes/GNL/get_next_line_utils.c

SRCCUB =   readmap.c #main.c

SRCMLX = includes/minilibx

SRCLIBFT = includes/libft

CC = gcc 
RM = rm -f
all: $(NAME)

$(NAME):
	@make -C $(SRCLIBFT)
	@make -C $(SRCMLX)
	${CC} ${SRC}  includes/libft/libft.a  ${SRCGNL} includes/minilibx/libmlx.a ${SRCCUB}  -framework OpenGL -framework AppKit 
	
bonus:
	@make -C $(SRCLIBFT)
	@make -C $(SRCMLX)
	${CC}  ${SRC}  includes/libft/libft.a ${SRCGNL} includes/minilibx/libmlx.a ${SRCCUB} -framework OpenGL -framework AppKit

debug:
	${CC}  ${SRC}  includes/libft/libft.a ${SRCGNL} includes/minilibx/libmlx.a ${SRCCUB} -g  -framework OpenGL -framework AppKit

fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
	@echo "Cleaning Cub3d..."

clean:
	${RM} ${OBJ} ${OBJBONUS}
	@echo "Cleaning hashcode objects..."

re: fclean all

.PHONY: all clean fclean re bonus
