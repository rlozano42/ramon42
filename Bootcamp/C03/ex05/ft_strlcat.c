/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:48:58 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/21 21:43:49 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	result;

	i = 0;
	while (dest[i] != '\0')
		i++;
	result = 0;
	while (src[result] != '\0')
		result++;
	if  (i <=  size)
		result = result + i;
	else
		result = result + size;
	j = 0;
	while (src[j] != '\0'  && i + 1 < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (result);
}
