/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 13:24:45 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handle(t_gen *g)
{
	while (is_space(*g->param.line) == 1)
		g->param.line++;	
	if ((ft_strchr(g->param.line, 'R')) != NULL)
		ft_handleresolution(g);
	else if (ft_strnstr(g->param.line, "NO", 2) != NULL)
		ft_handlenorth(g);
	else if (ft_strnstr(g->param.line, "SO", 2) != NULL)
		ft_handlesouth(g);
	else if (ft_strnstr(g->param.line, "WE", 2) != NULL)
		ft_handlewest(g);
	else if (ft_strnstr(g->param.line, "EA", 2) != NULL)
		ft_handleeast(g);
	else if (ft_strnstr(g->param.line, "S ", 2) != NULL)
		ft_handlesprite(g);
	else if ((ft_strchr(g->param.line, 'F')) != NULL)
		ft_handlefloor(g);
	else if ((ft_strchr(g->param.line, 'C')) != NULL)
		ft_handleceiling(g);
	else if ((ft_strchr(g->param.line, '1') != NULL) && (g->param.flag == 0))
	{
		g->param.map = ft_strdup_gnl(g->param.line);
		g->param.map = ft_strjoin_gnl(g->param.map, "\n");
		ft_checkcolumn(g);
		g->param.column++;
	}
	else if (ft_strchr(g->param.line, '1') != NULL)
	{
		char *map2;
		int		x;
		

		x = 0;
		map2 = ft_strdup_gnl(g->param.line);
		while (x < g->param.row)
		{
			if (map2[x] == 'N' || map2[x] == 'S' || map2[x] == 'E' || map2[x] == 'W' || map2[x] == '2')
			{
				while (map2[x] == 'N' || map2[x] == 'S' || map2[x] == 'E' || map2[x] == 'W' )
				{				
					if (map2[x] == 'N' || map2[x] == 'S' || map2[x] == 'E' || map2[x] == 'W')
						map2[x] = '0';
					x++;
				}
			}
			if (map2[x] == '2')
				g->f.cspr++;
			x++;
		}
		g->param.map = ft_strjoin_gnl(g->param.map, map2);
		g->param.map = ft_strjoin_gnl(g->param.map, "\n");
		free(map2);
		ft_checkcolumn(g);
		g->param.column++;
	}
}

void	ft_handlesprite(t_gen *g)
{
	g->param.aux = ft_split(g->param.line, ' ');
	ft_check(g);
	ft_checkrouth(g);
	if (g->param.len == 2)
	{
		g->param.sprite = g->param.aux[1];
	}
	else
		ft_throw_error("ERROR check sprite");
}

void	ft_handlefloor(t_gen *g)
{
	g->param.line++;
	g->param.floor[0] = atoi(g->param.line);
	while (*g->param.line != ',')
		g->param.line++;
	g->param.line++;
	g->param.floor[1] = atoi(g->param.line);
	while (*g->param.line != ',')
		g->param.line++;
	g->param.line++;
	g->param.floor[2] = atoi(g->param.line);
	check_updown(g, 'f');

}

void	ft_handleceiling(t_gen *g)
{
	g->param.line++;
	g->param.ceiling[0] = atoi(g->param.line);
	while (*g->param.line != ',')
		g->param.line++;
	g->param.line++;
	g->param.ceiling[1] = atoi(g->param.line);
	while (*g->param.line != ',')
		g->param.line++;
	g->param.line++;
	g->param.ceiling[2] = atoi(g->param.line);
	while (*g->param.line == ' ' || ft_isdigit(*g->param.line))
		g->param.line++;
	g->param.line++;
	check_updown(g, ' ');
}


char		**copy_matrix(int n_row, char **map)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char**)malloc((n_row + 1) * sizeof(char*));
	while (i < n_row)
	{
		matrix[i] = ft_strdup_gnl(map[i]);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	ft_readmap(char *mapa, t_gen *g)
{
	int		end;
	int y = 0;
	ft_bzero(g, sizeof(t_gen));
	char **map2;
	
	
	g->param.fd = open(mapa, O_RDONLY);
	while ((end = get_next_line(g->param.fd, &g->param.line)) >= 0)
	{
		ft_handle(g);
		if (end == 0)
		{
			g->param.finalmap = ft_split(g->param.map, '\n');
			map2 = copy_matrix(g->param.column, g->param.finalmap);
			final_checkmap(g);
			if (check_map(map2, g->param.position_x, g->param.position_y, g->param.column, g->param.row) == 1)
				ft_throw_error("Map is not closed");

//		printf("Filas: %d", g->param.row);
//		printf("Mapa:\n%s", g->param.map);
//	printf("R %d, %d\n", g->param.resolution_x, g->param.resolution_x);
//	printf("No %s\n", g->param.north);
//	printf("S %s\n", g->param.sprite);
/*	while (g->param.finalmap[y] != NULL)
	{
		printf("%s\n", g->param.finalmap[y]);
		y++;
	}*/

			break;
		}
	}
}
