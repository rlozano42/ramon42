/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/22 10:32:28 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <string.h>

void	ft_handle(t_map *param)
{
	if ((ft_strchr(param->line, 'R')) != NULL)
		ft_handleresolution(param);
	else if (ft_strchr(param->line, 'N') &&
	ft_strchr(++param->line, 'O') != NULL)
		ft_handlenorth(param);
	else if (ft_strnstr(param->line, "SO", 2) != NULL)
		ft_handlesouth(param);
	else if (ft_strchr(param->line, 'W') &&
	ft_strchr(++param->line, 'E') != NULL)
		ft_handlewest(param);
	else if (ft_strchr(param->line, 'E') &&
	ft_strchr(++param->line, 'A') != NULL)
		ft_handleeast(param);
	else if (ft_strnstr(param->line, "S ", 2) != NULL)
		ft_handlesprite(param);
	else if ((ft_strchr(param->line, 'F')) != NULL)
		ft_handlefloor(param);
	else if ((ft_strchr(param->line, 'C')) != NULL)
		ft_handleceiling(param);
}

void	ft_handlesprite(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	param->sprite = param->aux[1];
	printf("NO = %s\n", param->sprite);
}

void	ft_handlefloor(t_map *param)
{
	param->line++;
	param->floor[0] = atoi(param->line);
	printf("0 = %d\n", param->floor[0]);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->floor[1] = atoi(param->line);
	printf("1 = %d\n", param->floor[1]);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->floor[2] = atoi(param->line);
	printf("2 = %d\n", param->floor[2]);
}

void	ft_handleceiling(t_map *param)
{
	param->line++;
	param->ceiling[0] = atoi(param->line);
	printf("0 = %d\n", param->ceiling[0]);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->ceiling[1] = atoi(param->line);
	printf("1 = %d\n", param->ceiling[1]);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->ceiling[2] = atoi(param->line);
	printf("2 = %d\n", param->ceiling[2]);
}

int		main(int argc, char **argv)
{
	t_map param;

	argc = 1;
	param.fd = open(argv[1], O_RDONLY);
	while (get_next_line(param.fd, &param.line) > 0)
		ft_handle(&param);
}
