/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:44:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 11:03:07 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void	ft_put_texture(t_gen *g)
{
	if (g->f.txt_hit == 'N')
	{
		g->txt.txt_data = g->txt.txtn_data;
		g->txt.txt_sl = g->txt.txtn_sl;
		g->txt.txt_h = g->txt.txtn_h;
	}
	else if (g->f.txt_hit == 'S')
	{
		g->txt.txt_data = g->txt.txts_data;
		g->txt.txt_sl = g->txt.txts_sl;
		g->txt.txt_h = g->txt.txts_h;
	}
	else if (g->f.txt_hit == 'W')
	{
		g->txt.txt_data = g->txt.txtw_data;
		g->txt.txt_sl = g->txt.txtw_sl;
		g->txt.txt_h = g->txt.txtw_h;
	}
	else
	{
		g->txt.txt_data = g->txt.txte_data;
		g->txt.txt_sl = g->txt.txte_sl;
		g->txt.txt_h = g->txt.txte_h;
	}
}

void		ft_init_textures(t_gen *g)
{
	if (!(g->txt.txtn = mlx_xpm_file_to_image(g->mlx.mlx_ptr, g->param.north, &g->txt.txtn_w, &g->txt.txtn_h)))
        ft_throw_error("North texture can't be opened");
	g->txt.txtn_data = (int *)mlx_get_data_addr(g->txt.txtn, &g->txt.txtn_sb,&g->txt.txtn_sl, &g->txt.txtn_ed);
    
	
	if (!(g->txt.txts = mlx_xpm_file_to_image(g->mlx.mlx_ptr, g->param.south,&g->txt.txts_w, &g->txt.txts_h)))
        ft_throw_error("South texture can't be opened");
	g->txt.txts_data = (int *)mlx_get_data_addr(g->txt.txts, &g->txt.txts_sb,&g->txt.txts_sl, &g->txt.txts_ed);
	
	if (!(g->txt.txtw = mlx_xpm_file_to_image(g->mlx.mlx_ptr, g->param.west,&g->txt.txtw_w, &g->txt.txtw_h)))
        ft_throw_error("West texture can't be opened");
	g->txt.txtw_data = (int *)mlx_get_data_addr(g->txt.txtw, &g->txt.txtw_sb,&g->txt.txtw_sl, &g->txt.txtw_ed);
	
	if (!(g->txt.txte = mlx_xpm_file_to_image(g->mlx.mlx_ptr, g->param.east,&g->txt.txte_w, &g->txt.txte_h)))
        ft_throw_error("East texture can't be opened");
	g->txt.txte_data = (int *)mlx_get_data_addr(g->txt.txte, &g->txt.txte_sb,&g->txt.txte_sl, &g->txt.txte_ed);
	
	if (!(g->txt.txtp = mlx_xpm_file_to_image(g->mlx.mlx_ptr, g->param.sprite,&g->txt.txtp_w, &g->txt.txtp_h)))
        ft_throw_error("Sprite texture can't be opened");
	g->txt.txtp_data = (int *)mlx_get_data_addr(g->txt.txtp, &g->txt.txtp_sb,&g->txt.txtp_sl, &g->txt.txtp_ed);
}

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