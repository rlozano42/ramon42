/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:40:56 by uherrero          #+#    #+#             */
/*   Updated: 2019/10/13 20:54:12 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_strlen(char *str);

unsigned int	checkargv(int argc, char *argv[])
{
	unsigned int	count;
	char			*auxstr;

	auxstr = argv[1];
	count = 0;
	if (argc != 2)
		return (0);
	if (ft_strlen(auxstr) != 31)
		return (0);
	auxstr = argv[1];
	while (*auxstr != '\0')
	{
		if (!(count++ % 2))
		{
			if (*auxstr < '1' || *auxstr > '4')
				return (0);
		}
		else
		{
			if (*auxstr != ' ')
				return (0);
		}
		auxstr++;
	}
	return (1);
}

void			ft_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}

void			ft_cluessaves(char *argv[], char clues[])
{
	char			*auxsrc;
	char			*auxdest;
	unsigned int	count;

	count = 0;
	auxsrc = argv[1];
	auxdest = clues;
	while (*auxsrc != '\0' || count < 16)
	{
		if (!(count++ % 2))
			*(auxdest++) = *auxsrc;
		auxsrc++;
	}
	*auxdest = '\0';
}
