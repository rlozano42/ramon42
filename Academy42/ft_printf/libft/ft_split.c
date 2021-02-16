/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:03:25 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/04 16:51:45 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countword(char const *s, char c)
{
	int			world_count;
	int			count;

	count = 0;
	world_count = 0;
	while (s[count])
	{
		while (s[count] && s[count] == c)
			++count;
		if (s[count] && s[count] != c)
		{
			while (s[count] && s[count] != c)
				++count;
			world_count++;
		}
	}
	return (world_count);
}

static char		**fil(char **aux, char const *s, char c, int count)
{
	size_t		k;
	int			i;
	int			words_aux;

	i = 0;
	words_aux = 0;
	while ((s[i] && words_aux < count))
	{
		k = 0;
		while (s[i] && s[i] == c)
			++i;
		while (*(s + i + k) && *(s + i + k) != c)
			++k;
		if (k > 0)
			*(aux + words_aux++) = ft_substr(s, i, k);
		i = i + k;
	}
	return (aux);
}

char			**ft_split(char const *s, char c)
{
	char	**aux;
	int		count;

	if (!s)
		return (0);
	count = countword(s, c);
	if (!(aux = (char **)malloc(sizeof(char*) * (count + 1))))
		return (0);
	aux = fil(aux, s, c, count);
	aux[count] = NULL;
	return (aux);
}
