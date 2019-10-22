/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:58:36 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/21 09:15:18 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int	main()
{
	char src[] = "hola";
	char src2[50] = "adios";
	printf("%s\n", ft_strncat(src2, src, 10));
	printf("%s\n", strncat(src2, src, 10));
	return (0);
}
