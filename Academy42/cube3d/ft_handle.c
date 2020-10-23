/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:52:21 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/22 09:52:25 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <string.h>

void	ft_handleresolution(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	param->resolution_x = atoi(param->aux[1]);
	param->resolution_y = atoi(param->aux[2]);
	if (param->resolution_x > 1920 || param->resolution_y > 1080)
	{
		param->resolution_x = 1920;
		param->resolution_y = 1080;
	}
	if (param->resolution_x < 400 || param->resolution_y < 400)
	{
		param->resolution_x = 400;
		param->resolution_y = 400;
	}
	printf("X = %d\nY = %d\n", param->resolution_x, param->resolution_y);
}

void	ft_handlenorth(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	param->north = param->aux[1];
	printf("NO = %s\n", param->north);
}

void	ft_handlesouth(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	param->south = param->aux[1];
	printf("NO = %s\n", param->south);
}

void	ft_handlewest(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	param->west = param->aux[1];
	printf("NO = %s\n", param->west);
}

void	ft_handleeast(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	param->east = param->aux[1];
	printf("NO = %s\n", param->east);
}
