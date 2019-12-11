/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:45:36 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/06 12:59:34 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcmp(char *s1, char *s2)
{
	int			l;
	int			vuelt;

	l = 0;
	while (s1[l] || s2[l])
	{
		if (s1[l] != s2[l])
		{
			vuelt = s1[l] - s2[l];
			return (vuelt);
		}
		l++;
	}
	return (0);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		n;
	size_t		i;

	i = 0;
	if (big == NULL || little == NULL)
		return (NULL);
	if (big[0] == '\0' && little != '\0')
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	i = ft_strcmp((char *)big, (char *)little);
	if (i == 0)
		return ((char *)big);
	while (*big && len != 0)
	{
		n = 0;
		while (big[n] == little[n] && big[n] != '\0')
		{
			n++;
			if (little[n] == '\0' && n < len)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
