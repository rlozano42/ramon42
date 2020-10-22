/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:23:23 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:23:25 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*aux1;
	unsigned char		*aux2;

	aux1 = (const unsigned char *)src;
	aux2 = (unsigned char *)dest;
	if ((dest == NULL && src == NULL) || !n)
		return (dest);
	while (n > 0)
	{
		*aux2 = *aux1;
		aux1++;
		aux2++;
		n--;
	}
	return (dest);
}
