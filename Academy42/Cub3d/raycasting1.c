/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:44:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 13:15:15 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	rot_right(t_gen *g)
{
	double old_dir_x;
	double old_plane_x;

	if (g->f.rot_right)
	{
		old_dir_x = g->param.dirx;
		g->param.dirx = g->param.dirx *
			cos(-ROTSPEED) - g->param.diry * sin(-ROTSPEED);
		g->param.diry = old_dir_x *
			sin(-ROTSPEED) + g->param.diry * cos(-ROTSPEED);
		old_plane_x = g->param.planex;
		g->param.planex = g->param.planex *
			cos(-ROTSPEED) - g->param.planey * sin(-ROTSPEED);
		g->param.planey = old_plane_x *
			sin(-ROTSPEED) + g->param.planey * cos(-ROTSPEED);
	}
}

void	ft_rot(t_gen *g)
{
	double old_dir_x;
	double old_plane_x;

	if (g->f.rot_left)
	{
		old_dir_x = g->param.dirx;
		g->param.dirx = g->param.dirx *
			cos(ROTSPEED) - g->param.diry * sin(ROTSPEED);
		g->param.diry = old_dir_x *
			sin(ROTSPEED) + g->param.diry * cos(ROTSPEED);
		old_plane_x = g->param.planex;
		g->param.planex = g->param.planex *
			cos(ROTSPEED) - g->param.planey * sin(ROTSPEED);
		g->param.planey = old_plane_x *
			sin(ROTSPEED) + g->param.planey * cos(ROTSPEED);
	}
	rot_right(g);
}

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

void	ft_init_textures(t_gen *g)
{
	if (!(g->txt.txtn = mlx_xpm_file_to_image(g->mlx.mlx_ptr,
		g->param.north, &g->txt.txtn_w, &g->txt.txtn_h)))
		ft_throw_error("North texture can't be opened");
	g->txt.txtn_data = (int *)mlx_get_data_addr(g->txt.txtn,
		&g->txt.txtn_sb, &g->txt.txtn_sl, &g->txt.txtn_ed);
	if (!(g->txt.txts = mlx_xpm_file_to_image(g->mlx.mlx_ptr,
		g->param.south, &g->txt.txts_w, &g->txt.txts_h)))
		ft_throw_error("South texture can't be opened");
	g->txt.txts_data = (int *)mlx_get_data_addr(g->txt.txts,
		&g->txt.txts_sb, &g->txt.txts_sl, &g->txt.txts_ed);
	if (!(g->txt.txtw = mlx_xpm_file_to_image(g->mlx.mlx_ptr,
		g->param.west, &g->txt.txtw_w, &g->txt.txtw_h)))
		ft_throw_error("West texture can't be opened");
	g->txt.txtw_data = (int *)mlx_get_data_addr(g->txt.txtw,
		&g->txt.txtw_sb, &g->txt.txtw_sl, &g->txt.txtw_ed);
	if (!(g->txt.txte = mlx_xpm_file_to_image(g->mlx.mlx_ptr,
		g->param.east, &g->txt.txte_w, &g->txt.txte_h)))
		ft_throw_error("East texture can't be opened");
	g->txt.txte_data = (int *)mlx_get_data_addr(g->txt.txte,
		&g->txt.txte_sb, &g->txt.txte_sl, &g->txt.txte_ed);
	if (!(g->txt.txtp = mlx_xpm_file_to_image(g->mlx.mlx_ptr,
		g->param.sprite, &g->txt.txtp_w, &g->txt.txtp_h)))
		ft_throw_error("Sprite texture can't be opened");
	g->txt.txtp_data = (int *)mlx_get_data_addr(g->txt.txtp,
		&g->txt.txtp_sb, &g->txt.txtp_sl, &g->txt.txtp_ed);
}

void	ft_movement(t_gen *g)
{
	if (g->f.up)
	{
		if (g->param.finalmap[(int)(g->param.position_x + g->param.dirx *
			MOVESPEED)][(int)g->param.position_y] == '0')
			g->param.position_x += g->param.dirx * MOVESPEED;
		if (g->param.finalmap[(int)(g->param.position_x)][(int)
			(g->param.position_y + g->param.diry * MOVESPEED)] == '0')
			g->param.position_y += g->param.diry * MOVESPEED;
	}
	if (g->f.down)
	{
		if (g->param.finalmap[(int)(g->param.position_x - g->param.dirx *
			MOVESPEED)][(int)g->param.position_y] == '0')
			g->param.position_x -= g->param.dirx * MOVESPEED;
		if (g->param.finalmap[(int)(g->param.position_x)]
			[(int)(g->param.position_y - g->param.diry * MOVESPEED)] == '0')
			g->param.position_y -= g->param.diry * MOVESPEED;
	}
	ft_leftright(g);
	ft_rot(g);
	if (g->f.esc)
		ft_exit_game(&g->mlx);
}
