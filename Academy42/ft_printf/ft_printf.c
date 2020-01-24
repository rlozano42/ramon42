/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:54:32 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/23 17:02:51 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_checkprecision(ram *param)
{
	param->precision = ft_atoi(param->str);
	while (ft_isdigit(*param->str))
		param->str++;
}

void		ft_checkwidth(ram *param)
{
	param->width = ft_atoi(param->str);
	while (ft_isdigit(*param->str))
		param->str++;
}

void		ft_checkflags(ram *param)
{
	param->zero = 0;
	param->minus = 0;
	while (*param->str == '0' || *param->str == '-')
	{
		if (*param->str == '0')
			param->zero = 1;
		else if (*param->str == '-') 
			param->minus = 1;
		param->str++;
	}
	if ((param->zero == '1') && (param->minus == '1'))
		param->zero = 0;
}


int			ft_printf(const char *str, ...)
{
	ram param;
	param.len = 0;
	param.str = str;
	va_start(param.ap,str);
	while (*param.str)
	{
		if (*param.str == '%')
		{
			param.str++;
			if (*param.str == '0' || *param.str == '-')
				ft_checkflags(&param);
			else if (ft_isdigit(*param.str) || (*param.str == '.'))
				ft_checkall(&param);
			else if (ft_isalpha(*param.str) || *param.str == '%')
				ft_checktype(&param);
		}
		else
		{
			write(1, (param.str), 1);
			param.str++;
			param.len++;
		}
	}
	va_end(param.ap);
	return (param.len);
}

int main()
{
	int c;
	printf("Hola perica %.5d\n", 4);
	c = ft_printf("Hola perica %d\n", 4);
	printf("%d", c);
}
