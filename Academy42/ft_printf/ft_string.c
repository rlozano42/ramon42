/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:43:39 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stringminus(t_ram *param)
{
	if ((param->precision == param->arg) && (param->precision >= 0)
	&& (param->punt == 1))
		ft_precisionstr(param);
	else
	{
		while (*param->aux2)
		{
			write(1, &param->aux2[0], 1);
			param->aux2++;
			param->len++;
		}
	}
	ft_widthchar(param);
}

void	ft_normalstring(t_ram *param)
{
	if ((param->precision == param->arg) && (param->precision >= 0)
	&& (param->punt == 1))
	{
		ft_widthchar(param);
		ft_precisionstr(param);
	}
	else
	{
		ft_widthchar(param);
		while (*param->aux2)
		{
			write(1, &param->aux2[0], 1);
			param->aux2++;
			param->len++;
		}
	}
}

void	ft_string(t_ram *param)
{
	param->arg = 0;
	param->aux2 = va_arg(param->ap, char *);
	if (param->aux2 == NULL)
		param->aux2 = ft_strdup("(null)");
	param->arg = ft_strlen(param->aux2);
	if ((param->precision < param->arg) && (param->punt == 1))
		param->arg = param->precision;
	param->aux = param->aux2;
	if (param->minus == 1)
		ft_stringminus(param);
	else
		ft_normalstring(param);
	param->str++;
}
