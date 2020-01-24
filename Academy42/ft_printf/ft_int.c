/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:46 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/23 16:51:52 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal2(ram *param)
{
	unsigned int aux;
	char		*string;

	aux = va_arg(param->ap, unsigned int);
	string = ft_itoa_basebig(aux);
	while (*string)
	{
		write(1, &string[0], 1);
		string++;
		param->len++;
	}
	param->str++;
}

void ft_hexadecimal(ram *param)
{
	unsigned int aux;
	char		*string;

	aux = va_arg(param->ap, unsigned int);
	string = ft_itoa_basex(aux);
	while (*string)
	{
		write(1, &string[0], 1);
		string++;
		param->len++;
	}
	param->str++;
}

void ft_hexadecimalp(ram *param)
{
	unsigned long int		aux;
	char					*string;
	char					*final;

	aux = va_arg(param->ap,unsigned long int);
	string = ft_itoa_base(aux);
	final = ft_strjoin("0x", string);
	while (*final)
	{
		write(1, &final[0], 1);
		final++;
		param->len++;
	}
	param->str++;
}


void ft_number(ram *param)
{
	int 	num;
	char	*numb;

	num = va_arg(param->ap, int);
	numb = ft_itoa(num);
	while (*numb)
	{
		write(1, &numb[0], 1);
		numb++;
		param->len++;
	}
	param->str++;
}
