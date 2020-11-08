/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:33:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/08 13:33:09 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void			new_window(t_gen *g)
{
    if (!(g->mlx.mlx_ptr = mlx_init()))
		ft_throw_error("Failed minilibx connection");
	if (!(g->mlx.win_ptr = mlx_new_window(g->mlx.mlx_ptr, g->param.Screenwidth, g->param.Screenheight, "Cub3d")))
		ft_throw_error("There was a problem with window creation");
	if (!(g->mlx.img = mlx_new_image(g->mlx.mlx_ptr, g->param.Screenwidth, g->param.Screenheight)))
		ft_throw_error("Image cannot be created");
	g->mlx.addr = (int *)mlx_get_data_addr(g->mlx.img, &g->mlx.bits_per_pixel, &g->mlx.line_length,&g->mlx.endian);
}