/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:06:39 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/24 13:22:29 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;
	int		c;
	int		it;

	it = 0;
	c = ft_strlen(s);
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	while (it < c)
	{
		str[it] = s[it];
		it++;
	}
	str[c] = '\0';
	return (str);
}
