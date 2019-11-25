/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:16:02 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/21 21:48:19 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char dest[] = "hola";
//	char src[] = "adios";
	char src1[] = "adios";

//	printf("%u\n", ft_strlcat(dest, src,3));
	printf("%lu\n", strlcat(dest,src1,3));
}
