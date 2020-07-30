/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:41 by rlozano           #+#    #+#             */
/*   Updated: 2020/07/07 12:39:12 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen_gnl(const char *str)
{
	size_t x;

	x = 0;
	while (str[x])
	{
		x++;
	}
	return (x);
}

char		*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		count;
	size_t		start2;

	start2 = start;
	count = 0;
	if (s == NULL)
		return (0);
	if (start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	if (!(ptr = malloc((sizeof(char) * (len) + 1))))
		return (0);
	while (start < (len + start2))
		ptr[count++] = s[start++];
	ptr[count] = '\0';
	return (ptr);
}

char		*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (s[0] == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char		*ft_strdup_gnl(const char *s)
{
	char	*str;
	int		c;
	int		it;

	it = 0;
	c = ft_strlen_gnl(s);
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

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[x])
	{
		dst[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		dst[x] = s2[y];
		x++;
		y++;
	}
	free(s1);
	dst[x] = '\0';
	return (dst);
}
