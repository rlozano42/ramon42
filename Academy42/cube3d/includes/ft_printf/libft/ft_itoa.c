/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:35:50 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/30 15:07:10 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(long int nb)
{
	long int digit_n;

	digit_n = 1;
	if (nb == 0)
		return (1);
	if (nb <= 0)
	{
		nb = nb * -1;
		digit_n = digit_n + 1;
	}
	while (nb >= 10)
	{
		digit_n = digit_n + 1;
		nb = nb / 10;
	}
	return (digit_n);
}

char				*ft_itoa(int x)
{
	char			*aux;
	long int		n;
	long int		size;

	n = x;
	size = ft_size(n);
	if (!(aux = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
	{
		aux[0] = '-';
		n = n * -1;
	}
	else
		aux[0] = 0;
	aux[size] = '\0';
	while (size > (aux[0] == '-' ? 1 : 0))
	{
		size--;
		aux[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (aux);
}
