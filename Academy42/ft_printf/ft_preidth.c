/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:46:54 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/28 21:54:44 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_width(ram *param)
{
	int final;

	final = 0;
	final = param->width - param->arg;
	while(final > 0 && param->width > param->precision)
	{
		write(1, " ", 1);
		final--;
	}
}

void	ft_precision(ram *param)
{
	int final;

	final = 0;
	final = param->precision - param->arg;
	while(final > 0)
	{
		write(1, "0", 1);
		final--;
	}
}
void	ft_precisionstr(ram *param)
{
	int final;

	final = 0;
	final = param->precision;
	while (final > 0)
	{
		write(1,param->aux,1);
		final--;
		param->aux++;
	}
}