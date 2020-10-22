/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:36:25 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_ram *param)
{
	int final;

	final = 0;
	final = param->precision - param->arg;
	while (final > 0)
	{
		write(1, "0", 1);
		final--;
		param->len++;
		param->arg++;
	}
}

void	ft_widthzero(t_ram *param)
{
	while (param->final > 0 && param->width > param->precision)
	{
		write(1, "0", 1);
		param->final--;
		param->len++;
	}
}

void	ft_precisionstr(t_ram *param)
{
	int final;

	final = 0;
	final = param->precision;
	param->arg = 0;
	while (final > 0)
	{
		write(1, param->aux, 1);
		final--;
		param->aux++;
		param->len++;
		param->arg++;
	}
}

void	ft_precisionnum(t_ram *param)
{
	int final;

	final = 0;
	final = param->precision;
	while (final > 0)
	{
		write(1, " ", 1);
		final--;
		param->arg++;
	}
}
