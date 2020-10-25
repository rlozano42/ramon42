/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:52:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/23 14:25:54 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handleresolution(t_map *param)
{
		param->aux = ft_split(param->line, ' ');
		ft_check(param);
	if (param->len == 3)
	{
		param->resolution_x = atoi(param->aux[1]);
		param->resolution_y = atoi(param->aux[2]);
		if (param->resolution_x > MAX_RESOLUTIONX || param->resolution_y > MAX_RESOLUTIONY)
		{
			param->resolution_x = MAX_RESOLUTIONX;
			param->resolution_y = MAX_RESOLUTIONY;
		}
		if (param->resolution_x < MIN_RESOLUTIONX || param->resolution_y < MIN_RESOLUTIONY)
		{
			param->resolution_x = MIN_RESOLUTIONX;
			param->resolution_y = MIN_RESOLUTIONY;
		}
		printf("X = %d\nY = %d\n", param->resolution_x, param->resolution_y);
	}
	else
	{
		ft_throw_error("ERROR: check resolution");
	}
}

void	ft_handlenorth(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	ft_check(param);
	ft_checkrouth(param);
	if (param->len == 2)
	{
		param->north = param->aux[1];
		printf("NO = %s\n", param->north);
	}
	else
		ft_throw_error("ERROR: check north");
	
}

void	ft_handlesouth(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	ft_check(param);
	ft_checkrouth(param);
	if (param->len == 2)
	{
		param->south = param->aux[1];
		printf("SO = %s\n", param->south);
	}
	else
	{
		ft_throw_error("ERROR: check south");
	}
	
}

void	ft_handlewest(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	ft_check(param);
	ft_checkrouth(param);
	if (param->len == 2)
	{
		param->west = param->aux[1];
		printf("WE = %s\n", param->west);
	}
	else
	{
		ft_throw_error("ERROR: check west");
	}
}

void	ft_handleeast(t_map *param)
{
	
	param->aux = ft_split(param->line, ' ');
	ft_check(param);
	ft_checkrouth(param);
	if (param->len == 2)
	{
		param->east = param->aux[1];
		printf("EA = %s\n", param->east);
	}
	else
	{
		ft_throw_error("ERROR: check east");
	}
}
