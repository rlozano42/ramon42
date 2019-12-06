/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:17:24 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/05 20:05:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *aux;

	aux = dst;
	if (dst == NULL && src == NULL)
		return (0);
	if (n == 0)
		return (dst);
	while (n > 0)
	{
		if (n != 0)
		{
			*(char *)dst = *(char *)src;
			n--;
		}
		src++;
		dst++;
	}
	return (aux);
}
