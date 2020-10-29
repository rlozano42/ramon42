/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:20:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/29 12:58:34 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_throw_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	check_updown(t_map *param, char str)
{
	if (str == 'f')
	{
		if (param->floor[0] > 255 || param->floor[0] < 0 ||
		param->floor[1] > 255 || param->floor[1] < 0 ||
		param->floor[2] > 255 || param->floor[2] < 0)
		ft_throw_error("ERROR: Map is wrong, check floor");
	}
	else
	{
		if (param->ceiling[0] > 255 || param->ceiling[0] < 0 ||
		param->ceiling[1] > 255 || param->ceiling[1] < 0 ||
		param->ceiling[2] > 255 || param->ceiling[2] < 0)
		ft_throw_error("ERROR: Map is wrong, check ceiling");
	}
}

void	ft_check(t_map *param)
{
	param->len = 0;
	
	while (param->aux[param->len] != '\0')
		param->len++;
		
}

void    ft_checkrouth(t_map *param)
{
    if (ft_strnstr(param->aux[1], "./", 2) == NULL)
        ft_throw_error("ERROR: Check routh");
}

void ft_checkcolumn(t_map *param)
{
	int		len;
	param->flag   = 1;
	int	x = 0;
	
	len  = 0;
	while (*param->line != '\0')
	{
		x++;
		if (*param->line == 'N' || *param->line == 'S' || *param->line == 'E' || *param->line == 'W')
		{
			param->position_x = x;
			param->position_y = param->row;
//			printf("Posición %d, %d\n", param->position_y, param->position_x);
			*param->line = '0';
		}
		len++;
		param->line++;
	}
	if (len > param->column)
		param->column = len;
//	printf("Columnas %d\n", param->column);
}

int				check_map(char **map, int row, int col, t_map *param)
{
	int			ok;
	
	if (row < 0 || col < 0 || row >= param->row
	|| col >= param->column)
		return (1);
	if (map[row][col] == ' ')
		return(1);
	else if (map[row][col] == '3' || map[row][col] == '1')
		return (0);
	map[row][col] = '3';
	ok = check_map(map, row, col - 1, param);
	ok = ok == 0 ? check_map(map, row, col + 1, param) : ok;
	ok = ok == 0 ? check_map(map, row - 1, col, param) : ok;
	ok = ok == 0 ? check_map(map, row + 1, col, param) : ok;
	return (ok);
}

void		final_checkmap(t_map *param)
{
	int len;
	int y;
	
	y = 0;
	while (param->finalmap[y] != NULL)
	{
		len = ft_strlen_gnl(param->finalmap[y]);
		while (len < param->column)
		{
			param->finalmap[y] = ft_strjoin_gnl(param->finalmap[y], " ");
			len++;
		}
		y++;
	}
}