/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:22:51 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:22:52 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*aux;
	size_t	cont;

	cont = 0;
	aux = (char*)str;
	while (cont < n)
	{
		*aux = (char)c;
		cont++;
		aux++;
	}
	return (str);
}
