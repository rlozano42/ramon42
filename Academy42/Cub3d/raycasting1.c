/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:44:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/07 13:08:21 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void  ft_movement(t_gen *g)
{
    //move forward if no wall in front of you
    if (g->f.up)
    {
        if(g->param.finalmap[(int)(g->param.position_x + g->param.dirX * moveSpeed)][(int)g->param.position_y ] == '0') g->param.position_x += g->param.dirX * moveSpeed;
        if(g->param.finalmap[(int)(g->param.position_x)][(int)(g->param.position_y  + g->param.dirY * moveSpeed)] == '0') g->param.position_y += g->param.dirY * moveSpeed;
    }
    if (g->f.down)
    {
        if(g->param.finalmap[(int)(g->param.position_x - g->param.dirX * moveSpeed)][(int)g->param.position_y] == '0') g->param.position_x -= g->param.dirX * moveSpeed;
        if(g->param.finalmap[(int)(g->param.position_x)][(int)(g->param.position_y - g->param.dirY * moveSpeed)] == '0') g->param.position_y  -= g->param.dirY * moveSpeed;
    }
    if (g->f.left)
    {
        if (g->param.finalmap[(int)g->param.position_x][(int)(g->param.position_y + g->param.dirX * moveSpeed)] == '0') g->param.position_y += g->param.dirX * moveSpeed;
        if (g->param.finalmap[(int)(g->param.position_x - g->param.dirY * moveSpeed)][(int)g->param.position_y] == '0') g->param.position_x -= g->param.dirY * moveSpeed;
    }
    if (g->f.right)
    {
        if(g->param.finalmap[(int)g->param.position_x][(int)(g->param.position_y - g->param.dirX * moveSpeed)] == '0') g->param.position_y -= g->param.dirX * moveSpeed;
        if (g->param.finalmap[(int)(g->param.position_x + g->param.dirY * moveSpeed)][(int)g->param.position_y] == '0') g->param.position_x += g->param.dirY * moveSpeed;
    }
    if (g->f.rot_left)
    {
        double old_dir_x;
	    double old_plane_x;

	    old_dir_x = g->param.dirX;
	    g->param.dirX = g->param.dirX * cos(rotSpeed) - g->param.dirY * sin(rotSpeed);
	    g->param.dirY = old_dir_x * sin(rotSpeed) + g->param.dirY * cos(rotSpeed);
	    old_plane_x = g->param.planeX;
	    g->param.planeX = g->param.planeX * cos(rotSpeed) - g->param.planeY * sin(rotSpeed);
	    g->param.planeY = old_plane_x * sin(rotSpeed) + g->param.planeY * cos(rotSpeed);
    }
    if (g->f.rot_right)
    {
        double old_dir_x;
	    double old_plane_x;

	    old_dir_x = g->param.dirX;
	    g->param.dirX = g->param.dirX * cos(-rotSpeed) - g->param.dirY * sin(-rotSpeed);
	    g->param.dirY = old_dir_x * sin(-rotSpeed) + g->param.dirY * cos(-rotSpeed);
	    old_plane_x = g->param.planeX;
	    g->param.planeX = g->param.planeX * cos(-rotSpeed) - g->param.planeY * sin(-rotSpeed);
	    g->param.planeY = old_plane_x * sin(-rotSpeed) + g->param.planeY * cos(-rotSpeed);
    }
    if (g->f.esc)
        ft_exit_game(&g->mlx);
}