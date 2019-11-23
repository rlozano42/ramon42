/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:35:09 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/20 12:10:14 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1,const char *s2, size_t n)
{
	size_t l;

	l = 0;
	if (n == 0)
		return (0);
	while ((*s1 || *s2) && l < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			l++;
		}
		else if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
