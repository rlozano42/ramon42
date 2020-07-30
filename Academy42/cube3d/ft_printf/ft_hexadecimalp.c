/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimalp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:50:14 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_normalhexadecimalp(t_ram *param)
{
	if (param->width > 0)
		ft_widthchar(param);
	while (*param->final2)
	{
		write(1, &param->final2++[0], 1);
		param->len++;
		param->conv++;
	}
}

void	ft_minushexadecimalp(t_ram *param)
{
	while (*param->final2)
	{
		write(1, &param->final2++[0], 1);
		param->len++;
		param->conv++;
	}
	if (param->width > 0)
		ft_widthchar(param);
}

void	ft_hexadecimalp(t_ram *param)
{
	unsigned long int		aux;
	char					*string;

	param->conv = 0;
	param->arg = 0;
	aux = va_arg(param->ap, unsigned long int);
	if (aux == 0)
		string = "0";
	else
		string = ft_itoa_base(aux);
	if ((param->precision == 0) && (string[0] == '0') && (param->punt == 1))
		param->final2 = "0x";
	else
		param->final2 = ft_strjoin("0x", string);
	param->arg = ft_strlen(param->final2);
	if (param->minus == 1)
		ft_minushexadecimalp(param);
	else
		ft_normalhexadecimalp(param);
	param->str++;
}
