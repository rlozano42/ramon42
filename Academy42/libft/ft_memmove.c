/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:43:53 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/23 15:41:44 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *aux;

	aux = dst;
	if ((dst == NULL && src == NULL) || len <= 0)
		return (dst);
	if (src < dst)
	{
		src = src + (len - 1);
		dst = dst + (len - 1);
		while (len-- > 0)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
		return (aux);
	}
	while (len-- > 0)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (aux);
}
