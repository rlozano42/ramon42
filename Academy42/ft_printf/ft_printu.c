/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:07:42 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/23 17:04:22 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_precision(ram *param)
{

}

void ft_width(ram *param)
{


}

void ft_unsigned(ram *param)
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
