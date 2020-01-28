/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:46 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/28 21:59:14 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal2(ram *param)
{
	unsigned int aux;
	char		*string;

	param->conv = 0;
	param->arg = 0;
	aux = va_arg(param->ap, unsigned int);
	string = ft_itoa_basebig(aux);
	param->arg = ft_strlen(string);
	if (param->precision > 0)
		ft_precision(param);
	if (param->width > 0)
		ft_width(param);
	while (*string)
	{
		write(1, &string[0], 1);
		string++;
		param->len++;
		param->conv++;
	}
	param->str++;
}

void ft_hexadecimal(ram *param)
{
	unsigned int aux;
	char		*string;

	param->conv = 0;
	aux = va_arg(param->ap, unsigned int);
	string = ft_itoa_basex(aux);
	param->arg = ft_strlen(string);
	if (param->precision > 0)
		ft_precision(param);
	if (param->width > 0)
		ft_width(param);
	while (*string)
	{
		write(1, &string[0], 1);
		string++;
		param->len++;
		param->conv++;
	}
	param->str++;
}

void ft_hexadecimalp(ram *param)
{
	unsigned long int		aux;
	char					*string;
	char					*final;

	param->conv = 0;
	param->arg = 0;
	aux = va_arg(param->ap,unsigned long int);
	string = ft_itoa_base(aux);
	final = ft_strjoin("0x", string);
	param->arg = ft_strlen(final);
	if (param->precision > 0)
		ft_precision(param);
	if (param->width > 0)
		ft_width(param);
	while (*final)
	{
		write(1, &final[0], 1);
		final++;
		param->len++;
		param->conv++;
	}
	param->str++;
}


void ft_number(ram *param)
{
	int 	num;
	char	*numb;

	param->conv = 0;
	param->arg = 0;
	num = va_arg(param->ap, int);
	numb = ft_itoa(num);
	param->arg = ft_strlen(numb);
	if (param->precision > 0)
		ft_precision(param);
	if (param->width > 0)
		ft_width(param);
	while (*numb)
	{
		write(1, &numb[0], 1);
		numb++;
		param->len++;
		param->conv++;
	}
	param->str++;
}
