/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:29:10 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/04 16:48:33 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_clean(char c, char *set)
{
	size_t	i;
	size_t	lenset;

	i = 0;
	lenset = ft_strlen(set);
	while (i < lenset)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char		*aux;
	char		*dev;
	size_t		size_s;
	size_t		size_aux;
	size_t		num;

	if (!s1 || !set)
		return (0);
	while (ft_clean(s1[0], (char *)set))
		s1++;
	if (s1[0] == '\0')
		return (ft_strdup(""));
	size_s = ft_strlen(s1);
	aux = (char *)s1;
	while (*aux)
		aux++;
	aux--;
	while (ft_clean(aux[0], (char *)set))
		aux--;
	size_aux = ft_strlen(aux);
	num = size_s - (size_aux - 1);
	dev = ft_substr(s1, 0, (num));
	return ((char *)dev);
}
