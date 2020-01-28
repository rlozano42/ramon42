/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:17:52 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/28 16:25:11 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_init(ram *param)
{
    param->conv = 0;
    param->count = 0;
    param->arg = 0;
    param->len = 0;
    param->minus = 0;
    param->precision = 0;
    param->width = 0;
    param->zero = 0;
}