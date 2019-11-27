/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:45:36 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/26 13:35:06 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcmp(char *s1, char *s2)
{
	int l;
	int vuelta;

	l = 0;
	while (s1[l] || s2[l])
	{
		if (s1[l] != s2[l])
		{
			vuelta = s1[l] - s2[l];
			return (vuelta);
		}
		l++;
	}
	return (0);
}

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t		n;
	size_t		i;

	i = 0;
	if (big[0] == '\0' && little != '\0')
		return (0);
	if (little[0] == '\0')
		return (big);
	i = ft_strcmp(big, little);
	if (i == 0)
		return (big);
	while (*big && len != 0)
	{
		n = 0;
		while (big[n] == little[n] && big[n] != '\0')
		{
			n++;
			if (little[n] == '\0' && n < len)
				return (big);
		}
		big++;
		len--;
	}
	return (0);
}
