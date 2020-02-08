/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:17:52 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:17 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_ram *param)
{
	param->conv = 0;
	param->count = 0;
	param->arg = 0;
	param->len = 0;
	param->minus = 0;
	param->precision = 0;
	param->width = 0;
	param->zero = 0;
	param->punt = 0;
	param->min = 0;
	param->sign = 0;
	param->final = 0;
}
