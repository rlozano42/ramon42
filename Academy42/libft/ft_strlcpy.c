/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:50:43 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/05 13:00:37 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	x;
	int	count;
	int	size_count;

	count = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		count++;
	if (size == 0)
		return (count);
	x = 0;
	size_count = size - 1;
	while (src[x] != '\0' && x < size_count)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (count);
}
