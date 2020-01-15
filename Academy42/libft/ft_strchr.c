/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:20:50 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:20:52 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		cont;

	cont = 0;
	str = (char*)s;
	while (str[cont])
	{
		if (str[cont] == c)
			return (&str[cont]);
		cont++;
	}
	if (str[cont] == '\0' && c == '\0')
		return (&str[cont]);
	return (NULL);
}
