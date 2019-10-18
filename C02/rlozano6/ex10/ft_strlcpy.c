/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:07:03 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/17 22:03:33 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	x;
	int	count;
	int	size_count;

	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
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
