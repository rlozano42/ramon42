/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:08:07 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/11 13:58:26 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

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
