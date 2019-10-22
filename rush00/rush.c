/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:28:42 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/06 21:58:05 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);

void print_l1(int x)
{
	int i;

	i = 0;
	while (i <= x - 1)
	{
		if(i == 0)
		{
			ft_putchar('A');	
		}
		else if(i == x - 1)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
}

void print_lm(int x)
{
	int i;

	i = 0;
	while ( i <= x - 1)
	{
		if(i == 0 || i == x-1)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
}

void print_lf(int x)
{
	int i;

	i = 0;
	while ( i <= x - 1)
	{
		if(i == 0)
		{
			ft_putchar('A');
		}
		else if(i == x - 1)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
}

void rush(int x, int y)
{
	int j;

	j = 0;
	while (j <= y-1)
	{
		if ( j == 0)
		{
			print_l1(x);
		}
		else if ( j == y - 1)
		{
			print_lf(x);
		}
		else 
		{
			print_lm(x);
		}
		write(1, "\n", 1);
		j++;
	}
}
