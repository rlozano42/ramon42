/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:07:42 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/28 21:58:25 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_unsigned(ram *param)
{
	int 	num;
	char	*numb;

	param->conv = 0;
	num = va_arg(param->ap, int);
	numb = ft_itoa(num);
	param->arg = ft_strlen(numb);
	if (param->precision > 0)
		ft_precision(param);
	if (param->width > 0)
		ft_width(param);
	while (*numb)
	{
		write(1, &numb[0], 1);
		numb++;
		param->len++;
		param->conv++;
	}
	param->str++;
}
