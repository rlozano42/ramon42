/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aster.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:06:23 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/29 16:48:07 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_astwidth(ram *param)
{
    int nu;

    nu = 0;
    nu = va_arg(param->ap, int);
    if (nu < 0)
        param->minus = 1;
    if (nu == 0)
        param->zero = 1;
    param->width = nu;
	param->str++; 
    ft_checkall(param);
}
void ft_astpre(ram *param)
{
    int nu;

    nu = 0;
    nu = va_arg(param->ap, int); 
    param->precision = nu;
	param->str++; 
    ft_checkall(param);
}