# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 11:44:46 by rlozano           #+#    #+#              #
#    Updated: 2020/10/22 12:04:28 by rlozano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

SRC = ft_space.c ft_handle.c includes/ft_printf/libft/*.c 

SRCGNL = includes/GNL/get_next_line.c includes/GNL/get_next_line_utils.c

SRCCUB = main.c

SRCMLX = includes/minilibx

SRCLIBFT = includes/ft_printf/libft

SRCPRINTF = includes/ft_printf

CC = gcc 
RM = rm -f
all: $(NAME)

$(NAME):
	@make -C $(SRCLIBFT)
	@make -C $(SRCPRINTF)
	@make -C $(SRCMLX)
	${CC} ${SRC} includes/ft_printf/libftprintf.a includes/ft_printf/libft/libft.a  ${SRCGNL} includes/minilibx/libmlx.a ${SRCCUB}  #-framework OpenGL -framework AppKit 
	
bonus:
	@make -C $(SRCLIBFT)
	@make -C $(SRCPRINTF)
	@make -C $(SRCMLX)
	${CC}  ${SRC} includes/ft_printf/libftprintf.a  includes/ft_printf/libft/libft.a ${SRCGNL} includes/minilibx-linux/libmlx.a ${SRCCUB} #-framework OpenGL -framework AppKit

debug:
	${CC}  ${SRC} includes/ft_printf/libftprintf.a  includes/ft_printf/libft/libft.a ${SRCGNL} includes/minilibx-linux/libmlx.a ${SRCCUB} -g  #-framework OpenGL -framework AppKit

fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
	@echo "Cleaning Cub3d..."

clean:
	${RM} ${OBJ} ${OBJBONUS}
	@echo "Cleaning hashcode objects..."

re: fclean all

.PHONY: all clean fclean re bonus
