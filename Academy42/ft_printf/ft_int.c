/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:46 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_normalnumber2(t_ram *param)
{
	if ((param->min == 1) && (param->zero == 1))
	{
		write(1, "-", 1);
		param->len++;
		param->min = 0;
	}
	if (param->width > 0)
		ft_widthnumb(param);
	if (param->min == 1)
	{
		write(1, "-", 1);
		param->len++;
		param->min = 0;
	}
	if (param->precision > 0)
		ft_precision(param);
}

void	ft_normalnumber(t_ram *param)
{
	ft_normalnumber2(param);
	while (*param->numb2)
	{
		if ((param->punt == 1) && (param->precision == 0)
		&& (*param->numb2 == '0'))
		{
			ft_strdup("");
			break ;
		}
		if (param->min == 1)
		{
			write(1, "-", 1);
			param->len++;
			param->min = 0;
		}
		write(1, &param->numb2++[0], 1);
		param->len++;
		param->conv++;
	}
}

void	ft_numberminus(t_ram *param)
{
	while (*param->numb2)
	{
		if ((param->punt == 1) && (param->precision == 0)
		&& (*param->numb2 == '0'))
		{
			ft_strdup("");
			break ;
		}
		if (param->min == 1)
		{
			write(1, "-", 1);
			param->len++;
			param->min = 0;
		}
		if (param->precision > 0)
			ft_precision(param);
		write(1, &param->numb2[0], 1);
		param->numb2++;
		param->len++;
		param->conv++;
	}
	if (param->width > 0)
		ft_widthnumb(param);
	if (param->precision > 0)
		ft_precision(param);
}

void	ft_check(t_ram *param)
{
	if ((param->precision > 0) && (param->precision >= param->arg))
		param->arg = ft_strlen(param->numb2);
	else if ((param->punt == 1) && (param->precision == 0)
	&& (*param->numb2 == '0'))
		param->arg = 0;
	else
		param->arg = ft_strlen(param->numb2) + param->min;
}

void	ft_number(t_ram *param)
{
	long int	num;

	param->conv = 0;
	param->arg = 0;
	num = va_arg(param->ap, int);
	if (param->precision > 0 && param->zero == 1)
		param->zero = 0;
	if (num == -2147483648)
		num = 2147483648;
	else if (num < 0)
	{
		num = num * -1;
		param->min = 1;
		param->sign = 1;
	}
	param->numb2 = ft_itoa(num);
	param->arg = ft_strlen(param->numb2);
	ft_check(param);
	if (param->minus == 1)
		ft_numberminus(param);
	else
		ft_normalnumber(param);
	param->str++;
}
