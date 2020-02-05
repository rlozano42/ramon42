/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:07:42 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/05 19:00:35 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_five(ram *param)
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
void ft_unsigned(ram *param)
{
	unsigned int 	num;
	char	*numb;

	param->conv = 0;
	num = va_arg(param->ap, unsigned int);
	numb = ft_itoa(num);
	if (num == 0 && param->punt == 1 && param->precision == 0)
		numb = "";
	if (numb[0] == '\0' && num == 0 && param->punt == 0)
		numb = "0";
	param->arg = ft_strlen(numb);
	if (param->minus == 1)
	{
		if (param->precision > 0)
			ft_precision(param);
		while (*numb)
		{
			write(1, &numb[0], 1);
			numb++;
			param->len++;
			param->conv++;
		}
		ft_widthx(param);
	}
	else
	{
		if (param->width > 0)
			ft_widthx(param);
		if (param->precision > 0)
			ft_precision(param);
		while (*numb)
		{
			write(1, &numb[0], 1);
			numb++;
			param->len++;
			param->conv++;
		}
	}
	param->str++;
}
