/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:46:22 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/23 13:54:48 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include "includes/minilibx/mlx.h"
#include "includes/GNL/get_next_line.h"
#include "includes/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_RESOLUTIONX 1920
#define MAX_RESOLUTIONY 1080
#define MIN_RESOLUTIONX 400
#define MIN_RESOLUTIONY 400

typedef struct	s_cam{
	int			izq;
    int         drch;
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

typedef struct s_map
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
	int		len;
}				t_map;


void 			ft_initiate(t_cam *param);
int				down(int keycode, t_cam *param);
int				release(int keycode, t_cam *param);
int				test2(t_cam *param);
void			ft_handleresolution(t_map *param);
int				is_digit(char c);
int				is_space(char c);
void	ft_handleceiling(t_map *param);
void	ft_handlefloor(t_map *param);
void	ft_handlesprite(t_map *param);
void	ft_handleeast(t_map *param);
void	ft_handlewest(t_map *param);
void	ft_handlesouth(t_map *param);
void	ft_handlenorth(t_map *param);
void	ft_handleresolution(t_map *param);
void	ft_throw_error(const char  *str);
void	check_updown(t_map *param, char str);
void	ft_check(t_map *param);
void    ft_checkrouth(t_map *param);


#endif
