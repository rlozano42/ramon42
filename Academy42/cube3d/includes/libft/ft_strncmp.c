/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:19:24 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:19:26 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	if (n == 0)
		return (0);
	cont = 0;
	while (s1[cont] && s2[cont] && s1[cont] == s2[cont] && cont < n - 1)
		cont++;
	return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
}
