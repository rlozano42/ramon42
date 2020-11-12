/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 13:57:39 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_handlesprite(t_gen *g)
{
	g->param.sprite = save_texture(g);
	if (g->param.len != 2)
		ft_throw_error("ERROR check sprite");
}

void	ft_handlefloor(t_gen *g)
{
	int x;

	x = 0;
	x++;
	g->param.floor[0] = atoi(g->param.line + x);
	while (g->param.line[x] != ',')
		x++;
	x++;
	g->param.floor[1] = atoi(g->param.line + x);
	while (g->param.line[x] != ',')
		x++;
	x++;
	g->param.floor[2] = atoi(g->param.line + x);
	check_updown(g, 'f');
}

void	ft_handleceiling(t_gen *g)
{
	int x;

	x = 0;
	x++;
	g->param.ceiling[0] = atoi(g->param.line + x);
	while (g->param.line[x] != ',')
		x++;
	x++;
	g->param.ceiling[1] = atoi(g->param.line + x);
	while (g->param.line[x] != ',')
		x++;
	x++;
	g->param.ceiling[2] = atoi(g->param.line + x);
	while (g->param.line[x] == ' ' || ft_isdigit(g->param.line[x]))
		x++;
	x++;
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
	if ((g->param.fd = open(mapa, O_RDONLY)) <= 0)
		ft_throw_error("FD can't be opened");
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
			break ;
		}
	}
}
