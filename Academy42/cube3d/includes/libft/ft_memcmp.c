/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:24:52 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:24:53 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char		*aux1;
	char		*aux2;
	size_t		cont;

	cont = 0;
	aux1 = (char *)s1;
	aux2 = (char *)s2;
	while (n > 0)
	{
		if (aux1[cont] != aux2[cont])
			return (((unsigned char)aux1[cont]) - ((unsigned char)aux2[cont]));
		cont++;
		n--;
	}
	return (0);
}
