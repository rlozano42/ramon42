/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:54:32 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/08 12:35:43 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_checkprecision(t_ram *param)
{
	param->punt = 1;
	param->precision = ft_atoi(param->str);
	while (ft_isdigit(*param->str))
		param->str++;
}

void		ft_checkwidth(t_ram *param)
{
	param->width = ft_atoi(param->str);
	while (ft_isdigit(*param->str))
		param->str++;
}

void		ft_checkflags(t_ram *param)
{
	param->zero = 0;
	param->minus = 0;
	while (*param->str == '0' || *param->str == '-')
	{
		if (*param->str == '0')
			param->zero = 1;
		if (*param->str == '-')
			param->minus = 1;
		param->str++;
	}
	if ((param->zero == 1) && (param->minus == 1))
		param->zero = 0;
}

void		ft_printf2(t_ram *param)
{
	param->str++;
	if (*param->str == '0' || *param->str == '-')
		ft_checkflags(param);
	if (ft_isdigit(*param->str) || (*param->str == '.') || (*param->str == '*'))
		ft_checkall(param);
	if (ft_isalpha(*param->str) || *param->str == '%')
		ft_checktype(param);
}

int			ft_printf(const char *str, ...)
{
	t_ram param;

	ft_init(&param);
	param.str = (char *)str;
	va_start(param.ap, str);
	while (*param.str)
	{
		if (*param.str == '%')
			ft_printf2(&param);
		else
		{
			write(1, (param.str++), 1);
			param.len++;
		}
	}
	va_end(param.ap);
	return (param.len);
}

int main()
{
	ft_printf("Hola, %4.*s hola\n", -7, "ADIOD");
//	printf("Hola, %4.-5s hola", -7, "ADIOD");
	printf("Hola, %4.*s hola", -7, "ADIOD");
}