/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:32:13 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 13:29:32 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void ft_draw_sprites(t_gen *g)
{
    int		i;
    float tempx = 0;
    float tempy = 0;
    double dtemp = 0;
	double	dist[g->spr.cspr];

    i = -1;
    printf("%i\n", g->spr.cspr);
	while (++i < g->spr.cspr)
	{
		dist[i] = (pow((g->param.position_x - (double)g->spr.sprx[i]), 2) - pow((g->param.position_y - (double)g->spr.spry[i]), 2));
		g->spr.sortpprx[i] = g->spr.sprx[i];
		g->spr.sortppry[i] = g->spr.spry[i];
        i++;
	}
	i = -1;
	while (++i < g->spr.cspr - 1)
	{
		if (fabs(dist[i]) < fabs(dist[i + 1]))
		{
			dtemp = dist[i];
			dist[i] = dist[i + 1];
			dist[i + 1] = dtemp;
			tempx = g->spr.sortpprx[i];
	        tempy = g->spr.sortppry[i];
	        g->spr.sortpprx[i] = g->spr.sortpprx[i + 1];
	        g->spr.sortppry[i] = g->spr.sortppry[i + 1];
	        g->spr.sortpprx[i + 1] = tempx;
	        g->spr.sortppry[i + 1] = tempy;
			i = -1;
		}
	}


    while (i < g->spr.cspr)
	{
        printf("hola");
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
	    	if (g->spr.transformy > 0 && g->spr.stripe >= 0 && g->spr.stripe <
	    		g->param.Screenwidth && g->spr.transformy < g->spr.zbuffer[g->spr.stripe])
            g->spr.y = g->spr.drawstarty;
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
