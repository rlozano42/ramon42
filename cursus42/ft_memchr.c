/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:08:10 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/06 12:43:33 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*cpy;

	count = 0;
	cpy = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	while (n--)
	{
		if (*cpy == (unsigned char)c)
			return ((void *)cpy);
		cpy++;
	}
	return (0);
}
