/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:20:22 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:20:24 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		it;

	if (!dst)
		return (0);
	it = 0;
	len = ft_strlen(src);
	while (src[it] != '\0' && it < (int)(dstsize - 1))
	{
		dst[it] = src[it];
		it++;
	}
	if (dstsize)
		dst[it] = '\0';
	return (len);
}
