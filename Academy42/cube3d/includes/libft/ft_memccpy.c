/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:23:42 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:23:43 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*aux;
	const unsigned char		*aux2;
	size_t					i;

	i = 0;
	aux = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	while (i < n)
	{
		aux[i] = aux2[i];
		if (aux2[i] == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (0);
}
