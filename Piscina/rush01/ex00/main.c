/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:30:20 by uherrero          #+#    #+#             */
/*   Updated: 2019/10/13 20:49:13 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned int	checkargv(int argc, char *argv[]);
void			ft_error(void);
int				ft_strlen(char *str);
void			ft_cluessaves(char *argv[], char clues[]);

int				main(int argc, char *argv[])
{
	unsigned int	returned;
	char			*clues;

	clues = (char*)malloc(17);
	returned = checkargv(argc, &argv[0]);
	ft_cluessaves(&argv[0], clues);
	if (returned == 0)
	{
		ft_error();
		return (0);
	}
	while (*clues)
		write(1, clues++, 1);
	return (0);
}
