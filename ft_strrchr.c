/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:08 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/21 14:09:44 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char            *ft_strrchr(const char *s, int c)
{
    const char *temp;
    char aux;
    
	aux = (char)c;
	temp = s;
    while (*temp)
    {
        temp++;
    } 
    if (c == '\0')
        return ((char *)temp);
	while (--temp >= s)
		if (c == *temp)
			return ((char *)temp);
    return (0);
}
