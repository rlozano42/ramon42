/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:53:36 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/26 13:18:52 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 			ft_putendl_fd(char *s, int fd)
{
	int n;

	n = 0;
	if(s)
	{
		while (*(s + n))
		{
			write(fd, (s + n), 1);
			n++;
		}
		write(fd, "\n", 1);
	}
}