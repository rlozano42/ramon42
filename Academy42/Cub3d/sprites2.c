/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:57:08 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 12:55:38 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_sprite3(t_gen *g)
{
	while (g->spr.stripe < g->spr.drawendx)
	{
		g->spr.texx = (int)((g->spr.stripe - (-g->spr.spritewidth / 2
		+ g->spr.spritescreenx)) * g->txt.txtp_w / g->spr.spritewidth);
		if (g->spr.transformy > 0 && g->spr.stripe >= 0 && g->spr.stripe <
			g->param.screenwidth && g->spr.transformy
			< g->spr.zbuffer[g->spr.stripe])
			g->spr.y = g->spr.drawstarty;
		while (g->spr.y < g->spr.drawendy)
		{
			g->spr.d = (g->spr.y) * 256 - g->param.screenheight
				* 128 + g->spr.spriteheight * 128;
			g->spr.texy = ((g->spr.d * g->txt.txtp_h) /
				g->spr.spriteheight) / 256;
			if (*(g->txt.txtp_data + g->spr.texx +
				g->spr.texy * g->txt.txtp_sl / 4))
				*(g->mlx.addr + g->spr.stripe + g->spr.y *
				g->mlx.line_length / 4) =
				*(g->txt.txtp_data + g->spr.texx +
				g->spr.texy * g->txt.txtp_sl / 4);
			g->spr.y++;
		}
		g->spr.stripe++;
	}
}
