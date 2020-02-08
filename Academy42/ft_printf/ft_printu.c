/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:07:42 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_five(t_ram *param)
{
	param->arg = 1;
	if (param->minus == 1)
	{
		write(1, "\%", 1);
		param->str++;
		param->len++;
		if (param->precision > 0)
			ft_precision(param);
		if (param->width > 0)
			ft_widthfive(param);
	}
	else
	{
		if (param->precision > 0)
			ft_precision(param);
		if (param->width > 0)
			ft_widthfive(param);
		write(1, "\%", 1);
		param->str++;
		param->len++;
	}
}

void	ft_unsignedminus(t_ram *param)
{
	if (param->precision > 0)
		ft_precision(param);
	while (*param->numb)
	{
		write(1, &param->numb[0], 1);
		param->numb++;
		param->len++;
		param->conv++;
	}
	ft_widthx(param);
}

void	ft_normalunsigned(t_ram *param)
{
	if (param->width > 0)
		ft_widthx(param);
	if (param->precision > 0)
		ft_precision(param);
	while (*param->numb)
	{
		write(1, &param->numb[0], 1);
		param->numb++;
		param->len++;
		param->conv++;
	}
}

void	ft_unsigned(t_ram *param)
{
	unsigned int	num;

	param->conv = 0;
	num = va_arg(param->ap, unsigned int);
	param->numb = ft_unsigned_itoa(num);
	if (num == 0 && param->punt == 1 && param->precision == 0)
		param->numb = "";
	if (param->numb[0] == '\0' && num == 0 && param->punt == 0)
		param->numb = "0";
	param->arg = ft_strlen(param->numb);
	if (param->minus == 1)
		ft_unsignedminus(param);
	else
		ft_normalunsigned(param);
	param->str++;
}
