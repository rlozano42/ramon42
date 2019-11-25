/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:18:12 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/20 17:03:22 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int l;
	int vuelta;

	l = 0;
	while (s1[l] || s2[l])
	{
		if (s1[l] != s2[l])
		{
			vuelta = s1[l] - s2[l];
			return (vuelta);
		}
		l++;
	}
	return (0);
}
