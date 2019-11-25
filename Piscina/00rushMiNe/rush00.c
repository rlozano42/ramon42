/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 07:44:04 by pramos-d          #+#    #+#             */
/*   Updated: 2019/10/06 16:39:31 by pramos-d         ###   ########.fr       */
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
			ft_putchar('|');
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
			ft_putchar('-');
		}
		else if (i == 0)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('o');
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
			ft_putchar('-');
		}
		else if (i == 0)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('o');
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int j;

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
