/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:25:10 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/08 14:25:28 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	cont;

	cont = 0;
	result = malloc(size * nmemb);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size * nmemb);
	return (result);
}
