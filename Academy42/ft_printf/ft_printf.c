/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:54:32 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/05 18:53:26 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_checkprecision(ram *param)
{
	param->punt = 1;
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
		if (*param->str == '-') 
			param->minus = 1;
		param->str++;
	}
	if ((param->zero == 1) && (param->minus == 1))
		param->zero = 0;
}


int			ft_printf(const char *str, ...)
{
	ram param;
	
	ft_init(&param);
	param.str = (char *)str;
	va_start(param.ap,str);
	while (*param.str)
	{
		if (*param.str == '%')
		{
			param.str++;
			if (*param.str == '0' || *param.str == '-')
				ft_checkflags(&param);
			if (ft_isdigit(*param.str) || (*param.str == '.') || (*param.str == '*'))
				ft_checkall(&param);
			if (ft_isalpha(*param.str) || *param.str == '%')
				ft_checktype(&param);
		}
		else
		{
			write(1, (param.str++), 1);
			param.len++;
		}
	}
	va_end(param.ap);
	return (param.len);
}

/*int main()
{
	int h;
	int j;

	h = ft_printf("%u\n", INT_MAX + 1);
	j = printf("%u", INT_MAX + 1);
	printf("\n %d \n %d\n",h, j);
//	printf("Hola perica %5c %2c %4c %5c %6c %7c\n", 'g', 'u', 'j', 'p', 'y', 'u');
//	ft_printf("Hola perica %07d\n", 33);
//	printf("Hola perica %07i\n", 25);
//	ft_printf("Hola perica %07i\n", 25);
//	printf("Hola perica %7s\n", "hola");
//	ft_printf("Hola perica %7s\n", "hola");
//	printf("Hola perica %7p\n", "hola"); 
//	ft_printf("Hola perica %07p\n", "hola");
//	printf("Hola perica %07x\n", 45);
//	ft_printf("Hola perica %07x\n", 45);
//	printf("Hola perica %08X\n", 500);
//	ft_printf("Hola perica %08X\n", 500);
//	ft_printf("Hola perica %08u\n", 455);
//	printf("Hola perica %08u\n", 455);
}*/