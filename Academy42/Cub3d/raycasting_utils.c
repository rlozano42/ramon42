/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:32:11 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 13:05:58 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_rgb_int(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

void	dda2(t_gen *g)
{
	if (g->f.side == 0)
	{
		g->f.txt_hit = (g->f.mapx < g->param.position_x ? 'N' : 'S');
		g->f.perpwalldist = (g->f.mapx - g->param.position_x +
			(1 - g->f.stepx) / 2) / g->f.raydirx;
		g->f.wallx = g->param.position_y + g->f.perpwalldist * g->f.raydiry;
	}
	else
	{
		g->f.txt_hit = (g->f.mapy < g->param.position_y ? 'W' : 'E');
		g->f.perpwalldist = (g->f.mapy - g->param.position_y +
			(1 - g->f.stepy) / 2) / g->f.raydiry;
		g->f.wallx = g->param.position_x + g->f.perpwalldist * g->f.raydirx;
	}
}

void	ft_draw(t_gen *g, int x)
{
	int j;

	g->f.wallx -= floor(g->f.wallx);
	g->txt.txt_x = g->f.wallx * (g->txt.txt_sl / 4);
	if ((g->f.side == 0 && g->f.raydirx > 0) ||
		(g->f.side == 1 && g->f.raydiry < 0))
		g->txt.txt_x = (g->txt.txt_sl / 4) - g->txt.txt_x - 1;
	j = 0;
	g->f.txtstep = 1.0 * g->txt.txt_h / g->f.lineheight;
	g->f.txtpos = (g->f.drawstart - g->param.screenheight
		/ 2 + g->f.lineheight / 2) * g->f.txtstep;
	while (j < g->f.drawstart)
		*(g->mlx.addr + j++ * g->param.screenwidth + x) =
		ft_rgb_int(g->param.ceiling[0],
		g->param.ceiling[1], g->param.ceiling[2]);
	while (j < g->f.drawend)
	{
		*(g->mlx.addr + x + j++ * g->mlx.line_length / 4) =
			*(g->txt.txt_data + g->txt.txt_x +
			(int)g->f.txtpos * g->txt.txt_sl / 4);
		g->f.txtpos += g->f.txtstep;
	}
	while (j < g->param.screenheight)
		*(g->mlx.addr + j++ * g->param.screenwidth + x) =
		ft_rgb_int(g->param.floor[0], g->param.floor[1], g->param.floor[2]);
}

int		ft_exit_game(t_cam *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_game(t_gen *g)
{
	ft_movement(g);
	init_raycasting(g);
	ft_draw_sprites(g);
	mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img, 0, 0);
	return (0);
}
