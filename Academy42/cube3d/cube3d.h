/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:46:22 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/21 14:11:20 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include "includes/minilibx/mlx.h"
#include "includes/GNL/get_next_line.h"
#include "includes/ft_printf/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct	s_cam{
	int			up;
	int			down;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			i;
	int			j;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_cam;

typedef struct s_man
{
	int		fd;
	char	*line;
	int		resolution_x;
	int		resolution_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	**aux;
	int 	floor[3];
	int		ceiling[3];
}				t_man;


//void 			ft_init(t_cam *param);
//int				down(int keycode, t_cam *param);
//int				release(int keycode, t_cam *param);
//int				test2(t_cam *param);
void			ft_handleresolution(t_man *param);
int				is_digit(char c);
int				is_space(char c);

#endif
