/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:30:15 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/22 09:31:46 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put(char c)
{
	write(1, &c, 1);
}

void	ft_tramp(void)
{
	ft_put('-');
	ft_put('2');
	ft_put('1');
	ft_put('4');
	ft_put('7');
	ft_put('4');
	ft_put('8');
	ft_put('3');
	ft_put('6');
	ft_put('4');
	ft_put('8');
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
	return (digit_n);
}

void	ft_putnbr(int nb)
{
	int		digit_n;
	char	x;

	if (nb == -2147483648)
	{
		ft_tramp();
	}
	else
	{
		if (nb < 0)
		{
			nb = nb * -1;
			ft_put('-');
		}
		digit_n = ft_size(nb);
		while (digit_n > 0)
		{
			x = '0' + nb / digit_n;
			nb = (nb % digit_n);
			ft_put(x);
			digit_n = (digit_n / 10);
		}
	}
}
