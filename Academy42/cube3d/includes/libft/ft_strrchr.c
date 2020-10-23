/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:21:08 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:21:10 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		cont;

	cont = 0;
	str = (char*)s;
	while (str[cont])
		cont++;
	while (cont >= 0)
	{
		if (str[cont] == c)
			return (&str[cont]);
		cont--;
	}
	return (NULL);
}
