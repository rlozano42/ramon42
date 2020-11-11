/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 14:12:19 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
//	free_str(g->param.aux);
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

char	**copy_matrix(int n_row, char **map)
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
	char	**map2;
	int		x;
	int		y;

	ft_bzero(g, sizeof(t_gen));
	g->param.fd = open(mapa, O_RDONLY);
	while ((end = get_next_line(g->param.fd, &g->param.line)) >= 0)
	{
		ft_handle(g);
		if (end == 0)
		{
			g->param.finalmap = ft_split(g->param.map, '\n');
			map2 = copy_matrix(g->param.column, g->param.finalmap);
			final_checkmap(g);
			x = g->param.position_x;
			y = g->param.position_y;
			if (check_map(map2, x, y, g) == 1)
				ft_throw_error("Map is not closed");
			free_str(map2);
			ft_charge_sprites(g, 0, 0, 0);
			break ;
		}
	}
}
