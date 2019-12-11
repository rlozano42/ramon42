/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:20:04 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/09 18:03:31 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prin(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		ft_prin(a, b, c);
		if (c == '9' && b != '8')
		{
			b++;
			c = b + 1;
		}
		else if (c == '9' && b == '8' && a <= '7')
		{
			a++;
			b = a + 1;
			c = b + 1;
		}
		else
			c++;
	}
}
