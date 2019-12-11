/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:21:44 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/24 13:11:51 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*cpy;
	size_t		i;

	if (!(cpy = malloc(nmemb * size)))
		return (0);
	i = 0;
	while (i < (nmemb * size))
	{
		cpy[i] = 0;
		i++;
	}
	return (cpy);
}
