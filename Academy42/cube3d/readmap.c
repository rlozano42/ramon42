/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/27 13:58:32 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handle(t_map *param)
{
	while (is_space(*param->line) == 1)
		param->line++;	
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
	else if ((ft_strchr(param->line, '1') != NULL) && (param->flag == 0))
	{
		param->map = ft_strdup(param->line);
		param->map = ft_strjoin_gnl(param->map, "\n");
		ft_checkcolumn(param);
	}
	else if (ft_strchr(param->line, '1') != NULL)
	{
		param->row++;
		param->map2 = ft_strdup(param->line);
		param->map = ft_strjoin_gnl(param->map, param->map2);
		param->map = ft_strjoin_gnl(param->map, "\n");
		free(param->map2);
	}
}

void	ft_handlesprite(t_map *param)
{
	param->aux = ft_split(param->line, ' ');
	ft_check(param);
	ft_checkrouth(param);
	if (param->len == 2)
	{
		param->sprite = param->aux[1];
	}
	else
		ft_throw_error("ERROR: check sprite");
}

void	ft_handlefloor(t_map *param)
{
	param->line++;
	param->floor[0] = atoi(param->line);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->floor[1] = atoi(param->line);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->floor[2] = atoi(param->line);
	check_updown(param, 'f');

}

void	ft_handleceiling(t_map *param)
{
	param->line++;
	param->ceiling[0] = atoi(param->line);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->ceiling[1] = atoi(param->line);
	while (*param->line != ',')
		param->line++;
	param->line++;
	param->ceiling[2] = atoi(param->line);
	while (*param->line == ' ' || ft_isdigit(*param->line))
		param->line++;
	param->line++;
	check_updown(param, ' ');
}

int		main(int argc, char **argv)
{
	t_map param;
	int		end;
	
	argc = 1;
	param.fd = open(argv[1], O_RDONLY);
	while ((end = get_next_line(param.fd, &param.line)) >= 0)
	{
		ft_handle(&param);
		if (end == 0)
		{
			param.finalmap = ft_split(param.map, '\n');
			ft_check_map(&param);
//			printf("Filas: %d", param.row);
			printf("Mapa: %s", param.map);
			break;
		}
	}
}
