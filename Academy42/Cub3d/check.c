/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:20:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 13:45:00 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_checkrouth(t_gen *g)
{
	if (ft_strnstr(g->param.aux[1], "./", 2) == NULL)
		ft_throw_error("ERROR: Check routh");
}

void	ft_checkcolumn(t_gen *g)
{
	int		len;
	int		y;

	g->param.flag = 1;
	len = 0;
	y = 0;
	while (*g->param.line != '\0')
	{
		if (*g->param.line == 'N' || *g->param.line == 'S' ||
		*g->param.line == 'E' || *g->param.line == 'W')
		{
			g->param.position_x = g->param.column;
			g->param.position_y = y;
			g->param.whois = *g->param.line;
		}
		y++;
		len++;
		g->param.line++;
	}
	if (len > g->param.row)
		g->param.row = len;
}

int		check_map(char **map, int x, int y, t_gen *g)
{
	int			ok;
	char		c;

	if (g->param.position_x < 0 || g->param.position_y < 0
	|| g->param.position_x >= g->param.column
	|| g->param.position_y >= g->param.row)
		return (1);
	c = map[x][y];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[x][y] = '3';
	ok = check_map(map, x, y - 1, g);
	ok = ok == 0 ? check_map(map, x, y + 1, g) : ok;
	ok = ok == 0 ? check_map(map, x - 1, y, g) : ok;
	ok = ok == 0 ? check_map(map, x + 1, y, g) : ok;
	return (ok);
}

void	final_checkmap(t_gen *g)
{
	int len;
	int y;

	y = 0;
	while (g->param.finalmap[y] != NULL)
	{
		len = ft_strlen_gnl(g->param.finalmap[y]);
		while (len < g->param.row)
		{
			g->param.finalmap[y] = ft_strjoin_gnl(g->param.finalmap[y], " ");
			len++;
		}
		y++;
	}
}
