/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 08:09:29 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/09 17:28:33 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put(char c)
{
	write(1, &c, 1);
}

void	ft_work(int a, int b)
{
	char x;
	char y;

	x = '0' + (a / 10);
	y = '0' + (a % 10);
	ft_put(x);
	ft_put(y);
	ft_put(' ');
	x = '0' + (b / 10);
	y = '0' + (b % 10);
	ft_put(x);
	ft_put(y);
	if (a < 98)
	{
		ft_put(',');
		ft_put(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < b && a < 99)
	{
		while (b <= 99)
		{
			ft_work(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
