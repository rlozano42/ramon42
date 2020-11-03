/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/02 12:29:35 by rlozano          ###   ########.fr       */
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
	else if (ft_strnstr(param->line, "WE", 2) != NULL)
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
		param->row++;
	}
	else if (ft_strchr(param->line, '1') != NULL)
	{
		char *map2;
		int		x;

		x = 0;
		map2 = ft_strdup(param->line);
		if (ft_strchr(map2, 'W') != NULL)
		{
			while (map2[x] != '\0')
			{
				if (map2[x] == 'W')
					map2[x] = '0';
				x++;
			}
		}
		param->map = ft_strjoin_gnl(param->map, map2);
		param->map = ft_strjoin_gnl(param->map, "\n");
		free(map2);
		ft_checkcolumn(param);
		param->row++;
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
	int y = 0;
	ft_bzero(&param, sizeof(t_map));
	
	argc = 1;
	param.fd = open(argv[1], O_RDONLY);
	while ((end = get_next_line(param.fd, &param.line)) >= 0)
	{
		ft_handle(&param);
		if (end == 0)
		{
			param.finalmap = ft_split(param.map, '\n');
			final_checkmap(&param);
			if (check_map(param.position_x, param.position_y, &param) == 1)
				ft_throw_error("Map is not closed");
			else
				printf("\nFunciona");

//			printf("Filas: %d", param.row);
//		printf("Mapa:\n%s", param.map);
/*while (param.finalmap[y] != NULL)
{
	printf("%s\n", param.finalmap[y]);
	y++;
}*/
			break;
		}
	}
}
