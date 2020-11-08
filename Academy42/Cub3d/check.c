/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:20:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/08 14:09:09 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_throw_error(const char *str)
{
	char	*str2;

	str2 = ft_strjoin("Error\n", (char *)str);
	perror(str2);
	free(str2);
	exit(EXIT_FAILURE);
}

void	check_updown(t_gen *g, char str)
{
	if (str == 'f')
	{
		if (g->param.floor[0] > 255 || g->param.floor[0] < 0 ||
		g->param.floor[1] > 255 || g->param.floor[1] < 0 ||
		g->param.floor[2] > 255 || g->param.floor[2] < 0)
		ft_throw_error("ERROR: Map is wrong, check floor");
	}
	else
	{
		if (g->param.ceiling[0] > 255 || g->param.ceiling[0] < 0 ||
		g->param.ceiling[1] > 255 || g->param.ceiling[1] < 0 ||
		g->param.ceiling[2] > 255 || g->param.ceiling[2] < 0)
		ft_throw_error("ERROR: Map is wrong, check ceiling");
	}
}

void	ft_check(t_gen *g)
{
	g->param.len = 0;
	
	while (g->param.aux[g->param.len] != '\0')
		g->param.len++;
		
}

void    ft_checkrouth(t_gen *g)
{
    if (ft_strnstr(g->param.aux[1], "./", 2) == NULL)
        ft_throw_error("ERROR: Check routh");
}

void ft_checkcolumn(t_gen *g)
{
	int		len;
	g->param.flag = 1;
	int	y = 0;
	
	len  = 0;
	while (*g->param.line != '\0')
	{
		if (*g->param.line == 'N' || *g->param.line == 'S' || *g->param.line == 'E' || *g->param.line == 'W')
		{
			g->param.position_x = g->param.column;
			g->param.position_y = y;
			g->param.whois = *g->param.line;
//			printf("Whois: %c\n", g->param.whois);
		}
		y++;
		len++;
		g->param.line++;
	}
	if (len > g->param.row)
		g->param.row = len;
//	printf("Columnas %d\n", g->param.row);
}

int				check_map(char **map, int row, int col, int Maxrow, int Maxcol)
{
	int			ok;
	char		c;
	int y = 0;
	
	if (row < 0 || col < 0 || row >= Maxrow
	|| col >= Maxcol )
		return (1);
	c = map[row][col];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[row][col] = '3';
	ok = check_map(map, row, col - 1, Maxrow, Maxcol);
	ok = ok == 0 ? check_map(map, row, col + 1, Maxrow, Maxcol) : ok;
	ok = ok == 0 ? check_map(map, row - 1, col, Maxrow, Maxcol) : ok;
	ok = ok == 0 ? check_map(map, row + 1, col,  Maxrow, Maxcol) : ok;
	return (ok);
}

void		final_checkmap(t_gen *g)
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