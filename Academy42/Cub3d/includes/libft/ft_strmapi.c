/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:09:23 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/28 13:24:27 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*aux;
	size_t	count;
	size_t	len;

	count = 0;
	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	if (!(aux = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[count])
	{
		aux[count] = f(count, s[count]);
		count++;
	}
	aux[count] = '\0';
	return (aux);
}
