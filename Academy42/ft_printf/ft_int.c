/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:46 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/05 18:49:15 by rlozano          ###   ########.fr       */
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
	if (string[0] == '\0' && aux == 0 && param->punt == 0)
		string = "0";
	param->arg = ft_strlen(string);
	if (param->minus == 1)
	{
		if (param->precision > 0)
			ft_precision(param);
		while (*string)
		{
			write(1, &string[0], 1);
			string++;
			param->len++;
			param->conv++;
		}
		if (param->width > 0)
			ft_widthx(param);
	}
	else
	{
		if (param->width > 0)
			ft_widthx(param);
		if (param->precision > 0)
			ft_precision(param);
		while (*string)
		{
			write(1, &string[0], 1);
			string++;
			param->len++;
			param->conv++;
		}
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
	if (aux == 0 && param->punt == 1 && param->precision == 0)
		string = "";
	if (string[0] == '\0' && aux == 0 && param->punt == 0)
		string = "0";
	param->arg = ft_strlen(string);
	if (param->minus == 1)
	{
		if (param->precision > 0)
			ft_precision(param);
		while (*string)
		{
			write(1, &string[0], 1);
			string++;
			param->len++;
			param->conv++;
		}
		if (param->width > 0)
			ft_widthx(param);
	}
	else
	{
		if (param->width > 0)
			ft_widthx(param);
		if (param->precision > 0)
			ft_precision(param);
		while (*string)
		{
			write(1, &string[0], 1);
			string++;
			param->len++;
			param->conv++;
		}
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
	if (aux == 0)
		string = "0";
	else
		string = ft_itoa_base(aux);
	if ((param->precision == 0) && (string[0] == '0') && (param->punt == 1))
		final = "0x";
	else
		final = ft_strjoin("0x", string);
	param->arg = ft_strlen(final);
	if (param->minus == 1)
	{
		while (*final)
		{
			write(1, &final[0], 1);
			final++;
			param->len++;
			param->conv++;
		}
		if (param->width > 0)
			ft_widthchar(param);
	}
	else
	{
		if (param->width > 0)
			ft_widthchar(param);
		while (*final)
		{
			write(1, &final[0], 1);
			final++;
			param->len++;
			param->conv++;
		}
	}
	param->str++;
}


void ft_number(ram *param)
{
	long int 	num;
	char	*numb;
	
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
	numb = ft_itoa(num);
	param->arg = ft_strlen(numb);
	if ((param->precision > 0) && (param->precision >= param->arg))
		param->arg = ft_strlen(numb);
	else if ((param->punt == 1) && (param->precision == 0) && (*numb == '0'))
		param->arg = 0;
	else
		param->arg = ft_strlen(numb) + param->min;
	if (param->minus == 1)
	{
		
		while (*numb)
		{
			if ((param->punt == 1) && (param->precision == 0) && (*numb == '0'))
			{
				ft_strdup("");
				break;
			}
			if (param->min == 1)
			{
				write(1, "-",1);
				param->len++;
				param->min = 0;
			}
			if (param->precision > 0)
				ft_precision(param);
			write(1, &numb[0], 1);
			numb++;
			param->len++;
			param->conv++;
		}
		if (param->width > 0)
			ft_widthnumb(param);
		if (param->precision > 0)
			ft_precision(param);
	}
	else
	{
		if ((param->min == 1) && (param->zero == 1))
		{
			write(1, "-",1);
			param->len++;
			param->min = 0;
		}
		if (param->width > 0)
			ft_widthnumb(param);
		if (param->min == 1 )
		{
			write(1, "-",1);
			param->len++;
			param->min = 0;
		}
		if (param->precision > 0)
			ft_precision(param);
		while (*numb)
		{
			if ((param->punt == 1) && (param->precision == 0) && (*numb == '0'))
			{
				ft_strdup("");
				break;
			}
			if (param->min == 1)
			{
				write(1, "-",1);
				param->len++;
				param->min = 0;
			}
			write(1, &numb[0], 1);
			numb++;
			param->len++;
			param->conv++;
		}
	}
	param->str++;
}
