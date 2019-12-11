/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:51:50 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/06 13:28:55 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n < 0)
	{
		while (n >= 0)
		{
			if (*(char *)s1 != *(char *)s2)
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
			s1++;
			s2++;
			n--;		
		}
	}
	return (0);
}
