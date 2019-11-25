/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:27:38 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/14 10:27:42 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int z;
	int k;

	i = 1;
	z = 0;
	while (z < size - 1)
	{
		while (i < size)
		{
			if (tab[z] > tab[i])
			{
				k = tab[i];
				tab[i] = tab[z];
				tab[z] = k;
			}
			i++;
		}
		z++;
		i = z + 1;
	}
}
