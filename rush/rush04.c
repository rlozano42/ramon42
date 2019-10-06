/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:08:40 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/06 20:27:34 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	print_l1();
void	print_lm();
void	print-lf();

void rush(int x, int y)
{
	int j;
    
	j = 0;
	if(j == 0)
	{
		print_l1();
	}
	else if(j == y -1)
	{
		print_lf();
	}
	else
	{
		print_lf();
	}
}

void print_l1()
{
	if(j  == 0)
	{
		ft_putchar("A");
	}
	else if ( j < y -1)
	{
		ft_putchar("C");
	}
	else
	{
		ft_putchar("B");
	}

}
