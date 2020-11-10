/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:32:13 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 12:29:51 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_draw_sprites(t_gen *g)
{
    int		i;
    float tempx = 0;
    float tempy = 0;
    double dtemp = 0;
    int		x;
	double	dist[g->spr.cspr];

    i = 0;
	x = -1;
	while (++x < g->spr.cspr)
	{
		dist[x] = (pow((g->param.position_x - (double)g->spr.sprx[x]), 2) - pow((g->param.position_y - (double)g->spr.spry[x]), 2));
		g->spr.sortpprx[x] = g->spr.sprx[x];
		g->spr.sortppry[x] = g->spr.spry[x];
	}
	x = -1;
	while (++x < g->spr.cspr - 1)
	{
		if (fabs(dist[x]) < fabs(dist[x + 1]))
		{
			dtemp = dist[x];
			dist[x] = dist[x + 1];
			dist[x + 1] = dtemp;
			tempx = g->spr.sortpprx[i];
	        tempy = g->spr.sortppry[i];
	        g->spr.sortpprx[i] = g->spr.sortpprx[i + 1];
	        g->spr.sortppry[i] = g->spr.sortppry[i + 1];
	        g->spr.sortpprx[i + 1] = tempx;
	        g->spr.sortppry[i + 1] = tempy;
			x = -1;
		}
	}
    
    while (i < g->spr.cspr)
	{
		g->spr.spritex = (g->spr.sortpprx[i] + 0.5) - g->param.position_x;
		g->spr.spritey = (g->spr.sortppry[i] + 0.5) - g->param.position_y;
	    g->spr.invdet = 1.0 / (g->param.planeX * g->param.dirY - g->param.dirX * g->param.planeY);
	    g->spr.transformx = g->spr.invdet * (g->param.dirY * g->spr.spritex - g->param.dirX * g->spr.spritey);
	    g->spr.transformy = g->spr.invdet * (-g->param.planeY * g->spr.spritex + g->param.planeX * g->spr.spritey);
	    g->spr.spritescreenx = (int)((g->param.Screenwidth / 2) * (1 + g->spr.transformx / g->spr.transformy));
	    g->spr.spriteheight = abs((int)(g->param.Screenheight / g->spr.transformy));
	    g->spr.drawstarty = -g->spr.spriteheight / 2 + g->param.Screenheight / 2;
	    if (g->spr.drawstarty < 0)
	    	g->spr.drawstarty = 0;
	    g->spr.drawendy = g->spr.spriteheight / 2 + g->param.Screenheight / 2;
	    if (g->spr.drawendy >= g->param.Screenheight)
	    	g->spr.drawendy = g->param.Screenheight - 1;
	    g->spr.spritewidth = abs((int)(g->param.Screenheight / g->spr.transformy));
	    g->spr.drawstartx = -g->spr.spritewidth / 2 + g->spr.spritescreenx;
	    if (g->spr.drawstartx < 0)
	    	g->spr.drawstartx = 0;
	    g->spr.drawendx = g->spr.spritewidth / 2 + g->spr.spritescreenx;
	    if (g->spr.drawendx >= g->param.Screenwidth)
	    	g->spr.drawendx = g->param.Screenwidth - 1;		
	    	g->spr.stripe = g->spr.drawstartx;
        while (g->spr.stripe < g->spr.drawendx)
	    {
	        g->spr.texx = (int)((g->spr.stripe - (-g->spr.spritewidth / 2 + g->spr.spritescreenx)) * g->txt.txtp_w / g->spr.spritewidth);
	    	g->spr.y = g->spr.drawstarty;
	    	if (g->spr.transformy > 0 && g->spr.stripe >= 0 && g->spr.stripe <
	    		g->param.Screenwidth && g->spr.transformy < g->spr.zbuffer[g->spr.stripe])
	    		while (g->spr.y < g->spr.drawendy)
	    		{
	    			g->spr.d = (g->spr.y) * 256 - g->param.Screenheight * 128 + g->spr.spriteheight * 128;
                        g->spr.texy = ((g->spr.d * g->txt.txtp_h) / g->spr.spriteheight) / 256;
	    			if (*(g->txt.txtp_data + g->spr.texx + g->spr.texy * g->txt.txtp_sl / 4))
	    				*(g->mlx.addr + g->spr.stripe + g->spr.y * g->mlx.line_length / 4) = *(g->txt.txtp_data + g->spr.texx + g->spr.texy * g->txt.txtp_sl / 4);
	    			g->spr.y++;
	    	    }
	    g->spr.stripe++;
	    }
    i++;
    }
}
