/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:16:02 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/21 21:18:20 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int main()
{
	char str[] = "holamellamo ramon";
	char to_find[] = "am";

	printf("%s\n", ft_strstr(str,to_find));
}
