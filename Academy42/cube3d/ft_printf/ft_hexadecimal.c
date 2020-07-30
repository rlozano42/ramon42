/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:24:11 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minushexadecimal2(t_ram *param)
{
	if (param->precision > 0)
		ft_precision(param);
	while (*param->string2)
	{
		write(1, &param->string2[0], 1);
		param->string2++;
		param->len++;
		param->conv++;
	}
	if (param->width > 0)
		ft_widthx(param);
}

void	ft_hexadecimal2(t_ram *param)
{
	unsigned int	aux;

	param->conv = 0;
	param->arg = 0;
	aux = va_arg(param->ap, unsigned int);
	param->string2 = ft_itoa_basebig(aux);
	if (param->string2[0] == '\0' && aux == 0 && param->punt == 0)
		param->string2 = "0";
	param->arg = ft_strlen(param->string2);
	if (param->minus == 1)
		ft_minushexadecimal2(param);
	else
	{
		if (param->width > 0)
			ft_widthx(param);
		if (param->precision > 0)
			ft_precision(param);
		while (*param->string2)
		{
			write(1, &param->string2++[0], 1);
			param->len++;
			param->conv++;
		}
	}
	param->str++;
}

void	ft_minushexadecimal(t_ram *param)
{
	if (param->precision > 0)
		ft_precision(param);
	while (*param->string)
	{
		write(1, &param->string[0], 1);
		param->string++;
		param->len++;
		param->conv++;
	}
	if (param->width > 0)
		ft_widthx(param);
}

void	ft_normalhexadecimal(t_ram *param)
{
	if (param->width > 0)
		ft_widthx(param);
	if (param->precision > 0)
		ft_precision(param);
	while (*param->string)
	{
		write(1, &param->string[0], 1);
		param->string++;
		param->len++;
		param->conv++;
	}
}

void	ft_hexadecimal(t_ram *param)
{
	unsigned int	aux;

	param->conv = 0;
	aux = va_arg(param->ap, unsigned int);
	param->string = ft_itoa_basex(aux);
	if (aux == 0 && param->punt == 1 && param->precision == 0)
		param->string = "";
	if (param->string[0] == '\0' && aux == 0 && param->punt == 0)
		param->string = "0";
	param->arg = ft_strlen(param->string);
	if (param->minus == 1)
		ft_minushexadecimal(param);
	else
		ft_normalhexadecimal(param);
	param->str++;
}
