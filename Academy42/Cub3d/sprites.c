/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:32:13 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 14:25:04 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sort_sprite2(t_gen *g, float tempx, float tempy, int i)
{
	tempx = g->spr.sortpprx[i];
	tempy = g->spr.sortppry[i];
	g->spr.sortpprx[i] = g->spr.sortpprx[i + 1];
	g->spr.sortppry[i] = g->spr.sortppry[i + 1];
	g->spr.sortpprx[i + 1] = tempx;
	g->spr.sortppry[i + 1] = tempy;
}

void	sort_sprite(t_gen *g, float tempx, float tempy, double dtemp)
{
	int		i;
	double	dist[g->spr.cspr];

	i = 0;
	while (++i < g->spr.cspr)
	{
		dist[i] = (pow((g->param.position_x - (double)g->spr.sprx[i]), 2) -
		pow((g->param.position_y - (double)g->spr.spry[i]), 2));
		g->spr.sortpprx[i] = g->spr.sprx[i];
		g->spr.sortppry[i] = g->spr.spry[i];
	}
	i = -1;
	while (++i < g->spr.cspr - 1)
	{
		if (fabs(dist[i]) < fabs(dist[i + 1]))
		{
			dtemp = dist[i];
			dist[i] = dist[i + 1];
			dist[i + 1] = dtemp;
			sort_sprite2(g, tempx, tempy, i);
			i = 0;
		}
	}
}

void	ft_charge_sprites(t_gen *g, int m, int n, int i)
{
	g->spr.sprx = malloc(g->spr.cspr * sizeof(int));
	g->spr.spry = malloc(g->spr.cspr * sizeof(int));
	g->spr.sortpprx = malloc(g->spr.cspr * sizeof(int));
	g->spr.sortppry = malloc(g->spr.cspr * sizeof(int));
	while (n < g->param.column)
	{
		m = 0;
		while (m < g->param.row)
		{
			if (g->param.finalmap[n][m] == '2')
			{
				g->spr.sprx[i] = n;
				g->spr.spry[i] = m;
				g->spr.sortpprx[i] = n;
				g->spr.sortppry[i] = m;
				i++;
			}
			m++;
		}
		n++;
	}
}

void	draw_sprite2(t_gen *g)
{
	g->spr.invdet = 1.0 / (g->param.planex *
	g->param.diry - g->param.dirx * g->param.planey);
	g->spr.transformx = g->spr.invdet * (g->param.diry *
	g->spr.spritex - g->param.dirx * g->spr.spritey);
	g->spr.transformy = g->spr.invdet * (-g->param.planey *
	g->spr.spritex + g->param.planex * g->spr.spritey);
	g->spr.spritescreenx = (int)((g->param.screenwidth / 2) *
	(1 + g->spr.transformx / g->spr.transformy));
	g->spr.spriteheight = abs((int)(g->param.screenheight /
	g->spr.transformy));
	g->spr.drawstarty = -g->spr.spriteheight / 2 +
	g->param.screenheight / 2;
	if (g->spr.drawstarty < 0)
		g->spr.drawstarty = 0;
	g->spr.drawendy = g->spr.spriteheight / 2 + g->param.screenheight / 2;
	if (g->spr.drawendy >= g->param.screenheight)
		g->spr.drawendy = g->param.screenheight - 1;
	g->spr.spritewidth = abs((int)(g->param.screenheight
	/ g->spr.transformy));
	g->spr.drawstartx = -g->spr.spritewidth / 2 + g->spr.spritescreenx;
	if (g->spr.drawstartx < 0)
		g->spr.drawstartx = 0;
	g->spr.drawendx = g->spr.spritewidth / 2 + g->spr.spritescreenx;
	if (g->spr.drawendx >= g->param.screenwidth)
		g->spr.drawendx = g->param.screenwidth - 1;
}

void	ft_draw_sprites(t_gen *g)
{
	int i;

	i = 0;
	sort_sprite(g, 0, 0, 0);
	while (i < g->spr.cspr)
	{
		g->spr.spritex = (g->spr.sortpprx[i] + 0.5) - g->param.position_x;
		g->spr.spritey = (g->spr.sortppry[i] + 0.5) - g->param.position_y;
		draw_sprite2(g);
		g->spr.stripe = g->spr.drawstartx;
		draw_sprite3(g);
		i++;
	}
}
