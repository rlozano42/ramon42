/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:45:20 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 13:21:21 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*save_texture(t_gen *g)
{
	char	**num_str;
	char	*filename;

	num_str = ft_split(g->param.line, ' ');
	g->param.len = 0;
	while (num_str[g->param.len] != '\0')
		g->param.len++;
	filename = ft_strdup(num_str[1]);
	if (ft_strnstr(filename, "./", 2) == NULL)
		ft_throw_error("ERROR: Check routh");
	free_str(num_str);
	return (filename);
}

void	ft_handle4(t_gen *g)
{
	g->param.map = ft_strdup_gnl(g->param.line);
	g->param.map = ft_strjoin_gnl(g->param.map, "\n");
	ft_checkcolumn(g);
	g->param.column++;
}

void	ft_handle3(t_gen *g, char *map2, int x, int i)
{
	while (x < g->param.row)
	{
		if (map2[x] == 'N' || map2[x] == 'S' ||
			map2[x] == 'E' || map2[x] == 'W')
		{
			while (map2[x] == 'N' || map2[x] == 'S' ||
				map2[x] == 'E' || map2[x] == 'W')
			{
				if (map2[x] == 'N' || map2[x] == 'S' ||
					map2[x] == 'E' || map2[x] == 'W')
					map2[x] = '0';
				x++;
			}
		}
		if (map2[x] == '2')
			g->spr.cspr++;
		x++;
	}
	g->param.map = ft_strjoin_gnl(g->param.map, map2);
	g->param.map = ft_strjoin_gnl(g->param.map, "\n");
}

void	ft_handle2(t_gen *g)
{
	char	*map2;
	int		x;
	int		i;

	x = 0;
	i = 0;
	map2 = ft_strdup_gnl(g->param.line);
	ft_handle3(g, map2, x, i);
	free(map2);
	ft_checkcolumn(g);
	g->param.column++;
}

void	ft_handle(t_gen *g)
{
	g->param.x = 0;
	while (is_space(g->param.line[g->param.x]) == 1)
		g->param.x++;
	if ((g->param.free1 = ft_strchr(g->param.line, 'R')) != NULL)
		ft_handleresolution(g);
	else if ((g->param.free1 = ft_strnstr(g->param.line, "NO", 2)) != NULL)
		ft_handlenorth(g);
	else if ((g->param.free1 = ft_strnstr(g->param.line, "SO", 2)) != NULL)
		ft_handlesouth(g);
	else if ((g->param.free1 = ft_strnstr(g->param.line, "WE", 2)) != NULL)
		ft_handlewest(g);
	else if ((g->param.free1 = ft_strnstr(g->param.line, "EA", 2)) != NULL)
		ft_handleeast(g);
	else if ((g->param.free1 = ft_strnstr(g->param.line, "S ", 2)) != NULL)
		ft_handlesprite(g);
	else if ((g->param.free1 = ft_strchr(g->param.line, 'F')) != NULL)
		ft_handlefloor(g);
	else if ((g->param.free1 = ft_strchr(g->param.line, 'C')) != NULL)
		ft_handleceiling(g);
	else if (((g->param.free1 = ft_strchr(g->param.line, '1'))
		!= NULL) && (g->param.flag == 0))
		ft_handle4(g);
	else if ((g->param.free1 = ft_strchr(g->param.line, '1')) != NULL)
		ft_handle2(g);
	free(g->param.line);
}
