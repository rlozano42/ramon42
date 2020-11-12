/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:20:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 13:50:51 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_checkcolumn(t_gen *g)
{
	int		len;
	int		y;
	int		count;

	count = 0;
	g->param.flag = 1;
	len = 0;
	y = 0;
	while (g->param.line[count] != '\0')
	{
		if (g->param.line[count] == 'N' || g->param.line[count] == 'S' ||
		g->param.line[count] == 'E' || g->param.line[count] == 'W')
		{
			g->param.position_x = g->param.column;
			g->param.position_y = y;
			g->param.whois = g->param.line[count];
		}
		y++;
		len++;
		count++;
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
	int	x;

	x = 0;
	y = 0;
	while (g->param.finalmap[y][x] != '\0')
	{
		x = 0;
		len = ft_strlen(g->param.finalmap[y]);
		while (g->param.finalmap[y][x] != '\n')
		{
			if(x < g->param.row)
			{
				g->param.finalmap[y] = ft_strjoin_gnl(g->param.finalmap[y], " ");
				len++;
			}
			x++;
		}
		y++;
	}
}

