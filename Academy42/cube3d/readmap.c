/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/06 11:59:25 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handle(t_map *param)
{
	while (is_space(*param->line) == 1)
		param->line++;	
	if ((ft_strchr(param->line, 'R')) != NULL)
		ft_handleresolution(param);
	else if (ft_strnstr(param->line, "NO", 2) != NULL)
		ft_handlenorth(param);
	else if (ft_strnstr(param->line, "SO", 2) != NULL)
		ft_handlesouth(param);
	else if (ft_strnstr(param->line, "WE", 2) != NULL)
		ft_handlewest(param);
	else if (ft_strnstr(param->line, "EA", 2) != NULL)
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
		param->column++;
	}
	else if (ft_strchr(param->line, '1') != NULL)
	{
		char *map2;
		int		x;
		

		x = 0;
		map2 = ft_strdup(param->line);
		while (x < 25)
		{
			if (map2[x] == 'N' || map2[x] == 'S' || map2[x] == 'E' || map2[x] == 'W')
			{
				while (map2[x] != '\0')
				{
					if (map2[x] == 'N' || map2[x] == 'S' || map2[x] == 'E' || map2[x] == 'W')
						map2[x] = '0';
					x++;
				}
			}
			x++;
		}
		param->map = ft_strjoin_gnl(param->map, map2);
		param->map = ft_strjoin_gnl(param->map, "\n");
		map2 = ft_strdup("");
		ft_checkcolumn(param);
		param->column++;
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


char		**copy_matrix(int n_row, char **map)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char**)malloc((n_row + 1) * sizeof(char*));
	while (i < n_row)
	{
		matrix[i] = ft_strdup(map[i]);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	ft_readmap(char *mapa, t_map *param)
{
	int		end;
	int y = 0;
	ft_bzero(param, sizeof(t_map));
	char **map2;
	
	
	param->fd = open(mapa, O_RDONLY);
	while ((end = get_next_line(param->fd, &param->line)) >= 0)
	{
		ft_handle(param);
		if (end == 0)
		{
			param->finalmap = ft_split(param->map, '\n');
			map2 = copy_matrix(param->column, param->finalmap);
			final_checkmap(param);
			if (check_map(map2, param->position_x, param->position_y, param->column, param->row) == 1)
				ft_throw_error("Map is not closed");

//		printf("Filas: %d", param.row);
//		printf("Mapa:\n%s", param.map);
/*	while (param->finalmap[y] != NULL)
	{
		printf("%s\n", param->finalmap[y]);
		y++;
	}*/

			break;
		}
	}
}
