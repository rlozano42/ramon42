/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:52:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/08 13:31:03 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handleresolution(t_gen *g)
{
		g->param.aux = ft_split(g->param.line, ' ');
		ft_check(g);
	if (g->param.len == 3)
	{
		g->param.Screenwidth = atoi(g->param.aux[1]);
		g->param.Screenheight = atoi(g->param.aux[2]);
		if (g->param.Screenwidth > MAX_RESOLUTIONX || g->param.Screenheight > MAX_RESOLUTIONY)
		{
			g->param.Screenwidth = MAX_RESOLUTIONX;
			g->param.Screenheight = MAX_RESOLUTIONY;
		}
		if (g->param.Screenwidth < MIN_RESOLUTIONX || g->param.Screenheight < MIN_RESOLUTIONY)
		{
			g->param.Screenwidth = MIN_RESOLUTIONX;
			g->param.Screenheight = MIN_RESOLUTIONY;
		}
	}
	else
	{
		ft_throw_error("ERROR: check resolution");
	}
}

void	ft_handlenorth(t_gen *g)
{
	g->param.aux = ft_split(g->param.line, ' ');
	ft_check(g);
	ft_checkrouth(g);
	if (g->param.len == 2)
	{
		g->param.north = g->param.aux[1];
	}
	else
		ft_throw_error("ERROR: check north");
}

void	ft_handlesouth(t_gen *g)
{
	g->param.aux = ft_split(g->param.line, ' ');
	ft_check(g);
	ft_checkrouth(g);
	if (g->param.len == 2)
	{
		g->param.south = g->param.aux[1];
	}
	else
	{
		ft_throw_error("ERROR: check south");
	}
}

void	ft_handlewest(t_gen *g)
{
	g->param.aux = ft_split(g->param.line, ' ');
	ft_check(g);
	ft_checkrouth(g);
	if (g->param.len == 2)
	{
		g->param.west = g->param.aux[1];
	}
	else
	{
		ft_throw_error("ERROR: check west");
	}
}

void	ft_handleeast(t_gen *g)
{
	
	g->param.aux = ft_split(g->param.line, ' ');
	ft_check(g);
	ft_checkrouth(g);
	if (g->param.len == 2)
	{
		g->param.east = g->param.aux[1];
	}
	else
	{
		ft_throw_error("ERROR: check east");
	}
}
