/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:33:52 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/28 14:33:26 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_tramp(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putchar_fd('1', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('7', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
	ft_putchar_fd('3', fd);
	ft_putchar_fd('6', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
}

static int			ft_size(int n)
{
	int digit_n;

	digit_n = 1;
	while (n >= 10)
	{
		digit_n = digit_n * 10;
		n = n / 10;
	}
	return (digit_n);
}

void				ft_putnbr_fd(int n, int fd)
{
	int		digit_n;
	char	x;

	if (n == -2147483648)
	{
		ft_tramp(fd);
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		digit_n = ft_size(n);
		while (digit_n > 0)
		{
			x = '0' + n / digit_n;
			n = (n % digit_n);
			ft_putchar_fd(x, fd);
			digit_n = (digit_n / 10);
		}
	}
}
