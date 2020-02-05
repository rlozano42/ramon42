/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:17:15 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/05 13:17:47 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(ram *param)
{
	char *aux;

	param->arg = 0;
	aux = (char *)malloc(sizeof(char) * 2);
	aux[0] = (char)va_arg(param->ap, int);
	aux[1] = '\0';
	param->arg = ft_strlen(aux);
	if (*aux == 0)
		param->arg = 1;
	if (param->minus == 1)
	{
		write(1, &aux[0], 1);
		param->len++;
		ft_widthchar(param);
	}
	else
	{
		ft_widthchar(param);
		write(1, &aux[0], 1);
		param->len++;
	}
	param->str++;
}

void	ft_string(ram *param)
{
	char *aux;
	
	param->arg = 0;	
	aux = va_arg(param->ap, char*);
	if (aux == NULL)
		aux = ft_strdup("(null)");
	param->arg = ft_strlen(aux);
	if ((param->precision < param->arg) && (param->punt == 1))
		param->arg = param->precision;
	param->aux = aux;
	if (param->minus == 1)
	{
		if ((param->precision == param->arg) && (param->precision >= 0 ) && (param->punt == 1))
			ft_precisionstr(param);
		else
		{
			while (*aux)
			{
				write(1, &aux[0], 1);
				aux++;
				param->len++;
			}
		}
		ft_widthchar(param);
	}
	else
	{
		if ((param->precision == param->arg) && (param->precision >= 0 ) && (param->punt == 1))
		{
			ft_widthchar(param);
			ft_precisionstr(param);
		}
		else 
		{
			ft_widthchar(param);
			while (*aux)
			{
				write(1, &aux[0], 1);
				aux++;
				param->len++;
			}
		}
	}
	param->str++;
}

void ft_checktype(ram *param)
{

	if (*param->str == 'c')
		ft_char(param);
	else if (*param->str == 's')
		ft_string(param);
	else if (*param->str == 'd' || *param->str == 'i')
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
		ft_five(param);
}

void	ft_checkall(ram *param)
{
	if (*param->str == '*')
		ft_astwidth(param);
	else if (ft_isdigit(*param->str))
		ft_checkwidth(param);
	if (*param->str == '.')
	{
		param->str++;
		if (*param->str == '*')
			ft_astpre(param);
		else 
		ft_checkprecision(param);
	}
}
