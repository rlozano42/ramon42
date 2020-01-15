/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:24:16 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:24:18 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *src2;
	char *dst2;

	src2 = (char*)src;
	dst2 = dst;
	if ((dst == '\0' && src == '\0') || len <= 0)
		return (dst);
	if (src2 < dst2)
	{
		src2 = src2 + (len - 1);
		dst2 = dst2 + (len - 1);
		while (len-- > 0)
			*dst2-- = *src2--;
		return (dst);
	}
	while (len-- > 0)
		*dst2++ = *src2++;
	return (dst);
}
