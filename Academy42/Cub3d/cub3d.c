/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:37:02 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 09:36:19 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_initstruct(t_gen *g)
{
    g->f.time = 0;
    g->f.oldTime = 0;
    g->f.color = 0;
    g->f.cameraX = 0;
    g->f.rayDirX  = 0;
    g->f.rayDirY = 0;
    g->f.mapX = 0;
    g->f.mapY = 0;
    g->f.sideDistX = 0;
    g->f.sideDistY = 0;
    g->f.deltaDistX = 0;
    g->f.deltaDistY = 0;
    g->f.perpWallDist = 0;
    g->f.stepX  = 0;
    g->f.stepY = 0;
    g->f.side  = 0;
    g->f.lineHeight = 0;
    g->f.drawStart = 0;
    g->f.drawEnd = 0;
    g->f.frameTime = 0;
    g->f.keycode = 0;
    g->f.oldPlaneX = 0;
    g->f.oldDirX = 0;
    g->f.up = 0;
    g->f.down = 0;
    g->f.left = 0;
    g->f.right = 0;
    g->f.esc = 0;
    g->f.rot_right = 0;
    g->f.rot_left = 0;
}


int main(int argc, char **argv)
{
    t_gen g;
    
    ft_readmap(argv[1], &g);
    new_window(&g);
    ft_initstruct(&g);
//    printf("x = %d\ny = %d", g.param.position_x, g.param.position_y);
    g.param.position_x = g.param.position_x + 0.5;
    g.param.position_y = g.param.position_y + 0.5;
    ft_orientation(&g);
    init_raycasting(&g);
    mlx_hook(g.mlx.win_ptr, 2, 1, ft_key_press, &g);
	mlx_hook(g.mlx.win_ptr, 3, 2, ft_key_release, &g);
	mlx_hook(g.mlx.win_ptr, 17, 1, ft_exit_game, &g.mlx);
    mlx_put_image_to_window(g.mlx.mlx_ptr, g.mlx.win_ptr, g.mlx.img, 0, 0);
    mlx_loop_hook(g.mlx.mlx_ptr, ft_game, &g);
    mlx_loop(g.mlx.mlx_ptr);
    return(0);
}