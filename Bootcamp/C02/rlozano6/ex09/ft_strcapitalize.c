/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:38:39 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/17 22:02:04 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 65 && str[x] <= 90)
			str[x] = str[x] + 32;
		x++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int x;

	x = 0;
	ft_strlowcase(str);
	if (str[x] >= 97 && str[x] <= 122)
		str[x] = str[x] - 32;
	x = 1;
	while (str[x] != '\0')
	{
		if (!(str[x - 1] >= 97 && str[x - 1] <= 122))
			if (!(str[x - 1] >= 65 && str[x - 1] <= 90))
				if (!(str[x - 1] >= 48 && str[x - 1] <= 57))
					if (str[x] >= 97 && str[x] <= 122)
						str[x] = str[x] - 32;
		x++;
	}
	return (str);
}
