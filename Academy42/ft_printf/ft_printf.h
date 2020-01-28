/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:40:01 by rlozano           #+#    #+#             */
/*   Updated: 2020/01/28 21:40:02 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
#include <stdarg.h>
# include <unistd.h>
#include "libft/libft.h"

typedef struct		t_ram
{
	int count;
	unsigned int width;
	unsigned int zero;
	unsigned int minus;
	unsigned int precision;
	unsigned int len;
	unsigned int conv;
	unsigned int arg;
	const char *str;
	va_list		ap;
	char		*aux;
}					ram;

int		ft_printf(const char *string, ...);
void	ft_checkwidth(ram *param);
void	ft_checkprecision(ram *param);
void	ft_checkflags(ram *param);
void	ft_checktype(ram *param);
void	ft_char(ram *param);
void	ft_string(ram *param);
void	ft_hexadecimal(ram *param);
void	ft_number(ram *param);
void	ft_unsigned(ram *param);
void	ft_hexadecimal(ram *param);
void	ft_hexadecimal2(ram *param);
void	ft_por(char h);
void	ft_checkall(ram *param);
void	ft_hexadecimalp(ram *param);
int		ft_size(unsigned long int nb);
char	*ft_itoa_base(unsigned long int x);
char	*ft_itoa_basex(unsigned int x);
char	*ft_itoa_basebig(unsigned int x);
void	ft_unsigned(ram *param);
void	ft_width(ram *param);
void	ft_precision(ram *param);
void	ft_precisionstr(ram *param);
void	ft_init(ram *param);
#endif
