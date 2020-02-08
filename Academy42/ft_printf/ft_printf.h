/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:40:01 by rlozano           #+#    #+#             */
/*   Updated: 2020/02/06 16:21:30 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct		s_ram
{
	int				count;
	unsigned int	width;
	unsigned int	zero;
	unsigned int	minus;
	unsigned int	precision;
	unsigned int	len;
	unsigned int	conv;
	unsigned int	arg;
	char			*str;
	char			*string;
	char			*aux;
	int				punt;
	int				min;
	int				sign;
	char			*aux2;
	char			*numb;
	char			*numb2;
	int				final;
	char			*string2;
	char			*final2;
	va_list			ap;
}					t_ram;

int					ft_printf(const char *string, ...);
char				*ft_itoax(unsigned int n);
void				ft_checkwidth(t_ram *param);
void				ft_checkprecision(t_ram *param);
void				ft_checkflags(t_ram *param);
void				ft_checktype(t_ram *param);
void				ft_char(t_ram *param);
void				ft_string(t_ram *param);
void				ft_hexadecimal(t_ram *param);
void				ft_number(t_ram *param);
void				ft_unsigned(t_ram *param);
void				ft_hexadecimal(t_ram *param);
void				ft_hexadecimal2(t_ram *param);
void				ft_por(char h);
void				ft_checkall(t_ram *param);
void				ft_hexadecimalp(t_ram *param);
int					ft_size(unsigned long int nb);
char				*ft_itoa_base(unsigned long int x);
char				*ft_itoa_basex(unsigned int x);
char				*ft_itoa_basebig(unsigned int x);
void				ft_unsigned(t_ram *param);
void				ft_width(t_ram *param);
void				ft_widthchar(t_ram *param);
void				ft_precision(t_ram *param);
void				ft_precisionstr(t_ram *param);
void				ft_init(t_ram *param);
void				ft_widthnumb(t_ram *param);
void				ft_astpre(t_ram *param);
void				ft_astwidth(t_ram *param);
void				ft_widthfive(t_ram *param);
void				ft_five(t_ram *param);
void				ft_precisionnum(t_ram *param);
void				ft_widthx(t_ram *param);
char				*ft_unsigned_itoa(unsigned int x);
void				ft_printf2(t_ram *param);
void				ft_stringminus(t_ram *param);
void				ft_normalstring(t_ram *param);
void				ft_unsignedminus(t_ram *param);
void				ft_normalunsigned(t_ram *param);
void				ft_widthzero(t_ram *param);
void				ft_minushexadecimal(t_ram *param);
void				ft_normalhexadecimal(t_ram *param);
void				ft_minushexadecimalp(t_ram *param);
void				ft_normalhexadecimalp(t_ram *param);
void				ft_numberminus(t_ram *param);
void				ft_normalnumber(t_ram *param);
void				ft_normalnumber2(t_ram *param);
#endif
