/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:25:05 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 13:15:15 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_leftright(t_gen *g)
{
	if (g->f.left)
	{
		if (g->param.finalmap[(int)g->param.position_x]
			[(int)(g->param.position_y + g->param.dirx * MOVESPEED)] == '0')
			g->param.position_y += g->param.dirx * MOVESPEED;
		if (g->param.finalmap[(int)(g->param.position_x - g->param.diry
			* MOVESPEED)][(int)g->param.position_y] == '0')
			g->param.position_x -= g->param.diry * MOVESPEED;
	}
	if (g->f.right)
	{
		if (g->param.finalmap[(int)g->param.position_x]
			[(int)(g->param.position_y - g->param.dirx * MOVESPEED)] == '0')
			g->param.position_y -= g->param.dirx * MOVESPEED;
		if (g->param.finalmap[(int)(g->param.position_x + g->param.diry
			* MOVESPEED)][(int)g->param.position_y] == '0')
			g->param.position_x += g->param.diry * MOVESPEED;
	}
}
