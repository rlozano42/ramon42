/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:17:15 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_char(t_ram *param)
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

void		ft_checktype(t_ram *param)
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

void		ft_checkall(t_ram *param)
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
