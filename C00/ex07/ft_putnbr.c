/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:34:38 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/08 20:57:58 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_tramp()
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

int		ft_size(int nb)
{
	int digit_n;

	digit_n = 1;
	while (nb >= 10)
	{
		digit_n = digit_n * 10;
		nb = nb / 10;
	}
	return(digit_n);
}

void	ft_putnbr(int nb)
{
	int digit_n;
	char x;
	
	if (nb == -2147483648 )

	{
		ft_tramp();
	}
	else
	{
		if (nb < 0)
		{
			nb = nb  * -1;
			ft_putchar('-');
		}
		digit_n =ft_size(nb);
		while (digit_n  > 0)
		{
			x = '0' + nb/digit_n;
			nb = (nb % digit_n);
			ft_putchar(x);
			digit_n = (digit_n / 10);
		}
	}
}
