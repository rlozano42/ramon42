/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aster.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:06:23 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 18:03:08 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_astwidth(t_ram *param)
{
	int nu;

	nu = 0;
	nu = va_arg(param->ap, int);
	if (nu < 0)
	{
		param->minus = 1;
		nu *= -1;
	}
	if (nu == 0)
		param->zero = 1;
	param->width = nu;
	param->str++;
	if (param->minus == 1 && param->zero == 1)
		param->zero = 0;
	ft_checkall(param);
}

void	ft_astpre(t_ram *param)
{
	int nu;

	nu = 0;
	param->punt = 1;
	nu = va_arg(param->ap, int);
	if (nu < 0)
	{
		param->punt = 0;
		param->precision = 0;
		nu = 0;
	}
	param->precision = nu;
	param->str++;
	ft_checkall(param);
}
