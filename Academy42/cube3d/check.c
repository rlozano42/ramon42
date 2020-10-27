/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:20:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/10/27 13:59:42 by rlozano          ###   ########.fr       */
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
	param->column = 0;
	param->flag   = 1;
	param->row = 1;

	while (*param->line == '1')
	{
		param->column++;
		param->line++;
	}
//	printf("Columnas %d\n", param->row);
}

int				check_map(t_map *param)
{
	char		c;
	int			ok;

	if (param->row < 0 || param->column < 0 || param->row >= g_config.map.n_row
	|| param->column >= g_config.map.n_col)
		return (1);
	c = param->finalmap[param->row][param->column];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	param->finalmap[param->row][param->column] = '3';
	ok = check_map(param->finalmap, param->row, param->column - 1);
	ok = ok == 0 ? check_map(param->finalmap, param->row, param->column + 1) : ok;
	ok = ok == 0 ? check_map(param->finalmap, param->row - 1, param->column) : ok;
	ok = ok == 0 ? check_map(param->finalmap, param->row + 1, param->column) : ok;
	return (ok);
}