/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:37:02 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 13:57:57 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_initstruct2(t_gen *g)
{
	g->f.drawend = 0;
	g->f.frametime = 0;
	g->f.keycode = 0;
	g->f.oldplanex = 0;
	g->f.olddirx = 0;
	g->f.up = 0;
	g->f.down = 0;
	g->f.left = 0;
	g->f.right = 0;
	g->f.esc = 0;
	g->f.rot_right = 0;
	g->f.rot_left = 0;
}

void	ft_initstruct(t_gen *g)
{
	g->f.time = 0;
	g->f.oldtime = 0;
	g->f.color = 0;
	g->f.camerax = 0;
	g->f.raydirx = 0;
	g->f.raydiry = 0;
	g->f.mapx = 0;
	g->f.mapy = 0;
	g->f.sidedistx = 0;
	g->f.sidedisty = 0;
	g->f.deltadistx = 0;
	g->f.deltadisty = 0;
	g->f.stepx = 0;
	g->f.stepx = 0;
	g->f.stepy = 0;
	g->f.side = 0;
	g->f.lineheight = 0;
	g->f.drawstart = 0;
	ft_initstruct2(g);
}

int		main(int argc, char **argv)
{
	t_gen	g;

	g.param.bmp = 0;
	g.spr.cspr = 0;
	check_arg(argc, argv);
	ft_readmap(argv[1], &g);
	ft_charge_sprites(&g, 0, 0, 0);
	new_window(&g);
	ft_initstruct(&g);
	g.param.position_x = g.param.position_x + 0.5;
	g.param.position_y = g.param.position_y + 0.5;
	ft_orientation(&g);
	ft_init_textures(&g);
	init_raycasting(&g);
	if (argc == 3 && (g.param.free1 =
		ft_strnstr(argv[2], "--save\0", 6)) != NULL)
		g.param.bmp = 1;
	mlx_hook(g.mlx.win_ptr, 2, 1, ft_key_press, &g);
	mlx_hook(g.mlx.win_ptr, 3, 2, ft_key_release, &g);
	mlx_hook(g.mlx.win_ptr, 17, 1, ft_exit_game, &g.mlx);
	mlx_put_image_to_window(g.mlx.mlx_ptr, g.mlx.win_ptr, g.mlx.img, 0, 0);
	mlx_loop_hook(g.mlx.mlx_ptr, ft_game, &g);
	mlx_loop(g.mlx.mlx_ptr);
	return (0);
}
