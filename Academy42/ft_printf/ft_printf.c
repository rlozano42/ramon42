/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:54:32 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/28 22:00:17 by rlozano          ###   ########.fr       */
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
	ft_init(&param);
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
	printf("Hola perica %10c\n", 'g');
	ft_printf("Hola perica %10c\n", 'g');
	printf("Hola perica %3d\n", 33);
	ft_printf("Hola perica %3d\n", 33);
	printf("Hola perica %1s\n","hola");
	ft_printf("Hola perica %1s\n", "hola");
	printf("Hola perica %9i\n", 25);
	ft_printf("Hola perica %9i\n", 25);
	printf("Hola perica %10p\n", "hola"); 
	ft_printf("Hola perica %10p\n", "hola");
	printf("Hola perica %9x\n", 45);
	ft_printf("Hola perica %9x\n", 45);
	printf("Hola perica %9X\n", 500);
	ft_printf("Hola perica %9X\n", 500);
	ft_printf("Hola perica %9u\n", 39);
	printf("Hola perica %9u\n", 39);
}
