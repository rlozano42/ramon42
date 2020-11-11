/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:52:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 14:11:25 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handleresolution(t_gen *g)
{
	g->param.aux = ft_split(g->param.line, ' ');
	ft_check(g);
	if (g->param.len == 3)
	{
		g->param.screenwidth = atoi(g->param.aux[1]);
		g->param.screenheight = atoi(g->param.aux[2]);
		if (g->param.screenwidth > MAX_RESOLUTIONX ||
			g->param.screenheight > MAX_RESOLUTIONY)
		{
			g->param.screenwidth = MAX_RESOLUTIONX;
			g->param.screenheight = MAX_RESOLUTIONY;
		}
		if (g->param.screenwidth < MIN_RESOLUTIONX ||
			g->param.screenheight < MIN_RESOLUTIONY)
		{
			g->param.screenwidth = MIN_RESOLUTIONX;
			g->param.screenheight = MIN_RESOLUTIONY;
		}
	}
	else
	{
		ft_throw_error("ERROR: check resolution");
	}
//	free_str(g->param.aux);
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
//	free_str(g->param.aux);
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
//	free_str(g->param.aux);
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
//	free_str(g->param.aux);
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
//	free_str(g->param.aux);
}
