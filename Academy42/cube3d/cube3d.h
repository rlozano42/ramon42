/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:46:22 by rlozano           #+#    #+#             */
/*   Updated: 2020/07/07 19:58:09 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

//#include "minilibx-linux/mlx.h"
#include "GNL/get_next_line.h"
#include "ft_printf/ft_printf.h"
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

//void 			ft_init(t_cam *param);
//int				down(int keycode, t_cam *param);
//int				release(int keycode, t_cam *param);
//int				test2(t_cam *param);
int				is_digit(char c);
int				is_space(char c);

#endif
