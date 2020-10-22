/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/21 14:11:43 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <string.h>

void	ft_handleresolution(t_man *param)
{
			param->aux = ft_split(param->line, ' ');
			param->resolution_x = atoi(param->aux[1]);
			param->resolution_y = atoi(param->aux[2]);
			printf("X = %d\nY = %d\n", param->resolution_x, param->resolution_y);
}

int main(int argc, char **argv)
{
	t_man param;	

	argc = 1;
	param.fd = open(argv[1], O_RDONLY);
	while (get_next_line(param.fd, &param.line) > 0)
	{
		if ((ft_strchr(param.line, 'R')) != NULL)
			ft_handleresolution(&param);
		else if (ft_strchr(param.line, 'N') && ft_strchr(++param.line, 'O') != NULL)
		{
			param.aux = ft_split(param.line, ' ');
			param.north = param.aux[1];
			printf("NO = %s\n", param.north);
		}
		else if (ft_strnstr(param.line, "SO", 2) != NULL)
		{
			param.aux = ft_split(param.line, ' ');
			param.south = param.aux[1];
			printf("SO = %s\n", param.south);
		}
		else if (ft_strchr(param.line, 'W') && ft_strchr(++param.line, 'E') != NULL)
		{
			param.aux = ft_split(param.line, ' ');
			param.west = param.aux[1];
			printf("WE = %s\n", param.west);
		}
		else if (ft_strchr(param.line, 'E') && ft_strchr(++param.line, 'A') != NULL)
		{
			param.aux = ft_split(param.line, ' ');
			param.east = param.aux[1];
			printf("EA = %s\n", param.east);
		}
		else if (ft_strnstr(param.line, "S ", 2) != NULL)
		{
			param.aux = ft_split(param.line, ' ');
			param.sprite = param.aux[1];
			printf("S = %s\n", param.aux[1]);
		}
		else if ((ft_strchr(param.line, 'F')) != NULL)
		{
			param.line++;
			param.floor[0] = atoi(param.line);
			printf("0 = %d\n", param.floor[0]);
			while (*param.line != ',')
				param.line++;
			param.line++;
			param.floor[1] = atoi(param.line);
			printf("1 = %d\n", param.floor[1]);
			while (*param.line != ',')
				param.line++;
			param.line++;
			param.floor[2] = atoi(param.line);
			printf("2 = %d\n", param.floor[2]);
		}
		else if ((ft_strchr(param.line, 'C')) != NULL)
		{
			param.line++;
			param.ceiling[0] = atoi(param.line);
			printf("0 = %d\n", param.ceiling[0]);
			while (*param.line != ',')
				param.line++;
			param.line++;
			param.ceiling[1] = atoi(param.line);
			printf("1 = %d\n", param.ceiling[1]);
			while (*param.line != ',')
				param.line++;
			param.line++;
			param.ceiling[2] = atoi(param.line);
			printf("2 = %d\n", param.ceiling[2]);
		}
		
	}
}


