/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:31:59 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 13:06:22 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		init_calc(t_gen *g, int x)
{
	g->f.camerax = 2 * x / (double)g->param.screenwidth - 1;
	g->f.raydirx = g->param.dirx + g->param.planex * g->f.camerax;
	g->f.raydiry = g->param.diry + g->param.planey * g->f.camerax;
	g->f.mapx = g->param.position_x;
	g->f.mapy = g->param.position_y;
	g->f.deltadistx = fabs(1 / g->f.raydirx);
	g->f.deltadisty = fabs(1 / g->f.raydiry);
}

void		dda(t_gen *g)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (g->f.sidedistx < g->f.sidedisty)
		{
			g->f.sidedistx += g->f.deltadistx;
			g->f.mapx += g->f.stepx;
			g->f.side = 0;
		}
		else
		{
			g->f.sidedisty += g->f.deltadisty;
			g->f.mapy += g->f.stepy;
			g->f.side = 1;
		}
		if (g->param.finalmap[g->f.mapx][g->f.mapy] == '1')
			hit = 1;
	}
}

void		steps_initial_dist(t_gen *g)
{
	if (g->f.raydirx < 0)
	{
		g->f.stepx = -1;
		g->f.sidedistx = (g->param.position_x - g->f.mapx) * g->f.deltadistx;
	}
	else
	{
		g->f.stepx = 1;
		g->f.sidedistx = (g->f.mapx + 1.0 -
			g->param.position_x) * g->f.deltadistx;
	}
	if (g->f.raydiry < 0)
	{
		g->f.stepy = -1;
		g->f.sidedisty = (g->param.position_y - g->f.mapy) * g->f.deltadisty;
	}
	else
	{
		g->f.stepy = 1;
		g->f.sidedisty = (g->f.mapy + 1.0 -
			g->param.position_y) * g->f.deltadisty;
	}
}

void		init_raycasting(t_gen *g)
{
	int x;

	x = 0;
	while (x < g->param.screenwidth)
	{
		init_calc(g, x);
		steps_initial_dist(g);
		dda(g);
		dda2(g);
		g->spr.zbuffer[x] = g->f.perpwalldist;
		ft_put_texture(g);
		g->f.lineheight = (int)(g->param.screenheight / g->f.perpwalldist);
		g->f.drawstart = (-g->f.lineheight / 2) + g->param.screenheight / 2;
		if (g->f.drawstart < 0)
			g->f.drawstart = 0;
		g->f.drawend = (g->f.lineheight / 2) + g->param.screenheight / 2;
		if (g->f.drawend >= g->param.screenheight)
			g->f.drawend = g->param.screenheight - 1;
		ft_draw(g, x);
		x++;
	}
}
