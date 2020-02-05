/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:46:54 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/05 16:23:41 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_widthchar(ram *param)
{
	int final;

	final = 0;
	final = param->width - param->arg;
	param->width = 0;
	if (param->zero == 1)
	{
		while(final > 0)
		{
			write(1, "0", 1);
			final--;
			param->len++;
		}
	}
	else
	{
		while(final > 0)
		{
			write(1, " ", 1);
			final--;
			param->len++;
		}
	}
}
void ft_widthfive(ram *param)
{
	int final;

	final = 0;
	final = param->width - param->arg;
	param->width = 0;
	if (param->zero == 1)
	{
		while(final > 0)
		{
			write(1, "0", 1);
			final--;
			param->len++;
		}
		
	}
	else
	{	
		while(final > 0)
		{
			write(1, " ", 1);
			final--;
			param->len++;
		}
	}
}

void ft_widthnumb(ram *param)
{
	int final;

	final = 0;
	
	if ((param->width >= param->precision) && (param->minus == 1) && (param->sign == 1) && (param->precision >= param->arg))
		final = param->width - param->arg - param->sign;
	else if ((param->width > param->precision) && (param->sign == 1) && (param->precision >= param->arg))
		final = param->width - param->precision - param->sign;
	else if (param->precision > param->arg)
		final = param->width - param->precision - param->minus;
	else
		final = param->width - param->arg;
	if (param->zero == 1)
	{
		while(final > 0 && param->width > param->precision)
		{
			write(1, "0", 1);
			final--;
			param->len++;
		}
		
	}
	else
	{
		while(final > 0 && param->width > param->precision)
		{
			write(1, " ", 1);
			final--;
			param->len++;
		}
	}
}

void ft_width(ram *param)
{
	int final;

	final = 0;
	if (param->precision >= param->arg )
		final = param->width - param->precision;
	else
		final = param->width - param->arg;
	if (param->zero == 1)
	{
		while(final > 0 && param->width > param->precision)
		{
			write(1, "0", 1);
			final--;
			param->len++;
		}
	}
	else
	{
		while(final > 0 && param->width > param->precision)
		{
			write(1, " ", 1);
			final--;
			param->len++;
		}
	}
}
void ft_widthx(ram *param)
{
	int final;

	final = 0;
	if (param->precision >= param->arg )
		final = param->width - param->precision;
	else
		final = param->width - param->arg;
	if (param->zero == 1 && param->punt == 0)
	{
		while(final > 0 && param->width > param->precision)
		{
			write(1, "0", 1);
			final--;
			param->len++;
		}
	}
	else
	{
		while(final > 0 && param->width > param->precision)
		{
			write(1, " ", 1);
			final--;
			param->len++;
		}
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
		param->len++;
		param->arg++;
	}
}
void	ft_precisionstr(ram *param)
{
	int final;

	final = 0;
	final = param->precision;
	param->arg = 0;
	while (final > 0)
	{
		write(1,param->aux,1);
		final--;
		param->aux++;
		param->len++;
		param->arg++;
	}
}
void	ft_precisionnum(ram *param)
{
	int final;

	final = 0;
	final = param->precision;
	while (final > 0)
	{
		write(1, " ",1);
		final--;
		param->arg++;
	}
}