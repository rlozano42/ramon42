/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:34:49 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 13:47:30 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_unsignedsize(long int nb)
{
	long int digit_n;

	digit_n = 1;
	if (nb == 0)
		return (1);
	while (nb >= 10)
	{
		digit_n = digit_n + 1;
		nb = nb / 10;
	}
	return (digit_n);
}

char			*ft_unsigned_itoa(unsigned int x)
{
	char			*aux;
	long int		n;
	long int		size;

	n = x;
	size = ft_unsignedsize(n);
	if (!(aux = malloc(sizeof(char) * (size + 1))))
		return (0);
	aux[size] = '\0';
	while (size > 0)
	{
		size--;
		aux[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (aux);
}

char			*ft_itoa_basebig(unsigned int x)
{
	char					*hex;
	char					*base;
	unsigned long int		n;
	unsigned long int		digit_n;

	digit_n = -1;
	base = "0123456789ABCDEF";
	n = x;
	while (n >= 1)
	{
		digit_n++;
		n = n / 16;
	}
	if (n == 0)
		digit_n++;
	if (!(hex = malloc(sizeof(char) * (digit_n + 1))))
		return (0);
	hex[digit_n] = '\0';
	while (x != 0 || digit_n > 0)
	{
		digit_n--;
		hex[digit_n] = base[x % 16];
		x = x / 16;
	}
	return (hex);
}

char			*ft_itoa_basex(unsigned int x)
{
	char					*hex;
	char					*base;
	unsigned long int		n;
	unsigned long int		digit_n;

	digit_n = -1;
	base = "0123456789abcdef";
	n = x;
	while (n >= 1)
	{
		digit_n++;
		n = n / 16;
	}
	if (n == 0)
		digit_n++;
	if (!(hex = malloc(sizeof(char) * (digit_n + 1))))
		return (0);
	hex[digit_n] = '\0';
	while (x != 0 || digit_n > 0)
	{
		digit_n--;
		hex[digit_n] = base[x % 16];
		x = x / 16;
	}
	return (hex);
}

char			*ft_itoa_base(unsigned long int x)
{
	char						*hex;
	char						*base;
	unsigned long int			n;
	unsigned long int			digit_n;

	digit_n = 0;
	base = "0123456789abcdef";
	n = x;
	while (n >= 1)
	{
		digit_n = digit_n + 1;
		n = n / 16;
	}
	if (!(hex = malloc(sizeof(char) * (digit_n + 1))))
		return (0);
	hex[digit_n] = '\0';
	while (digit_n > 0)
	{
		digit_n--;
		hex[digit_n] = base[x % 16];
		x = x / 16;
	}
	return (hex);
}
