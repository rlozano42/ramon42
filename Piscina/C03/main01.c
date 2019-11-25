/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:24:24 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/17 13:28:02 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int 	main()
{
	char src[] = "cosa";
	char src2[] = "cose";
	int		r;
	
	r = ft_strncmp(src, src2, 4);

	printf("%d", r);
}
