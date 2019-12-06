/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:24:07 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/04 16:49:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*aux;
	size_t		s1_size;
	size_t		size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	if (!(aux = ft_calloc(sizeof(char), size + 1)))
		return (0);
	ft_memcpy(aux, s1, s1_size);
	ft_strlcat(aux, s2, size + 1);
	return (aux);
}
