/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:52:46 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/17 22:01:29 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_base16(char *b16)
{
	int b;
	int c;

	b = 0;
	c = 0;
	while (b <= 9)
	{
		b16[b] = b + 48;
		b++;
	}
	while (b <= 16)
	{
		b16[b] = 'a' + c;
		c++;
		b++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	b16[16];

	i = 0;
	ft_base16(b16);
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &b16[(unsigned char)str[i] / 16], 1);
			write(1, &b16[(unsigned char)str[i] % 16], 1);
		}
		i++;
	}
}
