/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:53:35 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/11 14:49:27 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int k;
	int aux;

	i = 0;
	k = size - 1;
	while (i < (size / 2))
	{
		aux = tab[i];
		tab[i] = tab[k];
		tab[k] = aux;
		i++;
		k--;
	}
}
