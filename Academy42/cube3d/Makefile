# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlozano <rlozano@student.42madrid.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 11:44:46 by rlozano           #+#    #+#              #
#    Updated: 2020/07/08 19:37:15 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d.a
SRC = ft_space.c ft_printf/libft/*.c 
SRCGNL = GNL/get_next_line.c GNL/get_next_line_utils.c
SRCCUB = readmap.c
CC = gcc 
RM = rm -f
all: $(NAME)
$(NAME): 
	${CC} ${SRC} ft_printf/libftprintf.a ft_printf/libft/libft.a  ${SRCGNL} minilibx-linux/libmlx.a ${SRCCUB}  #-framework OpenGL -framework AppKit 
bonus:
	${CC}  ${SRC} ft_printf/libftprintf.a  ft_printf/libft/libft.a ${SRCGNL} minilibx-linux/libmlx.a ${SRCCUB} #-framework OpenGL -framework AppKit
debug:
	${CC}  ${SRC} ft_printf/libftprintf.a  ft_printf/libft/libft.a ${SRCGNL} minilibx-linux/libmlx.a ${SRCCUB} -g  #-framework OpenGL -framework AppKit
fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
	@echo "Cleaning Cub3d..."
clean:
	${RM} ${OBJ} ${OBJBONUS}
	@echo "Cleaning hashcode objects..."

re: fclean all

.PHONY: all clean fclean re bonus
