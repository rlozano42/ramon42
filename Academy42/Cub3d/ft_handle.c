/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:52:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 11:54:33 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handleresolution(t_gen *g)
{
	char **aux;

	aux = ft_split(g->param.line, ' ');
	g->param.len = 0;
	while (aux[g->param.len] != '\0')
		g->param.len++;
	if (g->param.len == 3)
	{
		g->param.screenwidth = atoi(aux[1]);
		g->param.screenheight = atoi(aux[2]);
		if (g->param.screenwidth > MAX_RESOLUTIONX ||
			g->param.screenheight > MAX_RESOLUTIONY)
			resolutionmax(g);
		if (g->param.screenwidth < MIN_RESOLUTIONX ||
			g->param.screenheight < MIN_RESOLUTIONY)
		{
			g->param.screenwidth = MIN_RESOLUTIONX;
			g->param.screenheight = MIN_RESOLUTIONY;
		}
	}
	else
		ft_throw_error("ERROR: check resolution");
	free_str(aux);
}

void	ft_handlenorth(t_gen *g)
{
	g->param.north = save_texture(g);
	if (g->param.len != 2)
		ft_throw_error("ERROR: check north");
}

void	ft_handlesouth(t_gen *g)
{
	g->param.south = save_texture(g);
	if (g->param.len != 2)
		ft_throw_error("ERROR: check south");
}

void	ft_handlewest(t_gen *g)
{
	g->param.west = save_texture(g);
	if (g->param.len != 2)
		ft_throw_error("ERROR: check west");
}

void	ft_handleeast(t_gen *g)
{
	g->param.east = save_texture(g);
	if (g->param.len != 2)
		ft_throw_error("ERROR: check east");
}
