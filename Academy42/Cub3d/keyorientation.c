/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyorientation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:10:24 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 12:53:16 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_key_press(int keycode, t_gen *g)
{
	if (keycode == K_W)
		g->f.up = 1;
	if (keycode == K_S)
		g->f.down = 1;
	if (keycode == K_AR_R)
		g->f.rot_right = 1;
	if (keycode == K_AR_L)
		g->f.rot_left = 1;
	if (keycode == K_A)
		g->f.left = 1;
	if (keycode == K_D)
		g->f.right = 1;
	if (keycode == K_ESC)
		g->f.esc = 1;
	return (0);
}

int		ft_key_release(int keycode, t_gen *g)
{
	if (keycode == K_W)
		g->f.up = 0;
	if (keycode == K_S)
		g->f.down = 0;
	if (keycode == K_AR_R)
		g->f.rot_right = 0;
	if (keycode == K_AR_L)
		g->f.rot_left = 0;
	if (g->f.keycode == K_A)
		g->f.left = 0;
	if (keycode == K_D)
		g->f.right = 0;
	if (keycode == K_ESC)
		g->f.esc = 0;
	return (0);
}

void	ft_westeast(t_gen *g)
{
	if (g->param.whois == 'W')
	{
		g->param.dirx = 0.0;
		g->param.diry = -1.0;
		g->param.planex = -0.66;
		g->param.planey = 0.0;
	}
	if (g->param.whois == 'E')
	{
		g->param.dirx = 0.0;
		g->param.diry = 1.0;
		g->param.planex = 0.66;
		g->param.planey = 0.0;
	}
}

void	ft_orientation(t_gen *g)
{
	if (g->param.whois == 'N')
	{
		g->param.dirx = -1.0;
		g->param.diry = 0.0;
		g->param.planex = 0.0;
		g->param.planey = 0.66;
	}
	if (g->param.whois == 'S')
	{
		g->param.dirx = 1.0;
		g->param.diry = 0.0;
		g->param.planex = 0.0;
		g->param.planey = -0.66;
	}
	ft_westeast(g);
}
