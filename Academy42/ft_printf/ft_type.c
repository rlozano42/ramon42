/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:17:15 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/23 16:49:00 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(ram *param)
{
	char *aux;

	aux = (char *)malloc(sizeof(char) * 2);
	aux[0] = (char)va_arg(param->ap, int);
	aux[1] = '\0';
	write(1, &aux[0], 1);
	param->str++;
}

void	ft_string(ram *param)
{
	char *aux;

	aux = va_arg(param->ap, char*);
	while (*aux)
	{
		write(1, &aux[0], 1);
		aux++;
	}
	param->str++;
}

void ft_checktype(ram *param)
{
	if (*param->str == 'c')
		ft_char(param);
	else if (*param->str == 's')
		ft_string(param);
	else if (*param->str == 'd')
		ft_number(param);
	else if (*param->str == 'i')
		ft_number(param);
	else if (*param->str == 'p')
		ft_hexadecimalp(param);
	else if (*param->str == 'x')
		ft_hexadecimal(param);
	else if (*param->str == 'X')
		ft_hexadecimal2(param);
	else if (*param->str == 'u')
		ft_unsigned(param);
	else if (*param->str == '%')
	{
			write(1, "\%", 1);
			param->str++;
			param->len++;
	}
}

void	ft_checkall(ram *param)
{
	if (ft_isdigit(*param->str))
		ft_checkwidth(param);
	else if (*param->str == '.')
	{
		param->str++;
		ft_checkprecision(param);
	}
}
