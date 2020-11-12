/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:34:36 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 12:12:29 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_arg(int argc, char **argv)
{
	char *free1;

	if (argc == 3)
	{
		if ((free1 = ft_strnstr(argv[2], "--save\0", 6)) == NULL)
			ft_throw_error("Check third argument");
	}
	if (argc < 2 || argc > 3)
		ft_throw_error("Problem with arguments");
}

void	resolutionmax(t_gen *g)
{
	g->param.screenwidth = MAX_RESOLUTIONX;
	g->param.screenheight = MAX_RESOLUTIONY;
}

int		is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
