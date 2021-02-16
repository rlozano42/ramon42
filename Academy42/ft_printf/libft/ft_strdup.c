/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:26:03 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:26:04 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	aux = (char*)malloc(sizeof(char) * (size + 1));
	if (aux == 0)
		return (0);
	while (s[i])
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
