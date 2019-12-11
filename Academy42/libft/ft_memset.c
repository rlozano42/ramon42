/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:15:02 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/06 12:38:54 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*aux;
	size_t		cont;

	if (b == NULL)
		return (NULL);
	cont = 0;
	aux = (char*)b;
	while (cont < len)
	{
		aux[cont] = (char)c;
		cont++;
	}
	return (b);
}
