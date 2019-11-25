/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 07:44:04 by pramos-d          #+#    #+#             */
/*   Updated: 2019/10/08 16:29:51 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar();

void	print_lm(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i > 0 && i < x - 1)
		{
			ft_putchar(' ');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
	ft_putchar('\n');
}

void	print_l1(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i > 0 && i < x - 1)
		{
			ft_putchar('B');
		}
		else if (i == 0)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('C');
		}
		i++;
	}
	ft_putchar('\n');
}

void	print_lf(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i > 0 && i < x - 1)
		{
			ft_putchar('B');
		}
		else if (i == 0)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('A');
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int j;

	if (x != 0)
	{
		j = 0;
		while (j < y)
		{
			if (j == 0)
			{
				print_l1(x);
			}
			else if (j == y - 1)
			{
				print_lf(x);
			}
			else
			{
				print_lm(x);
			}
			j++;
		}
	}
}
