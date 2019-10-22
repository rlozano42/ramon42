/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:50:42 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/21 21:23:58 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		n;

	if (str[0] == '\0' && to_find != '\0')
		return (0);
	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		n = 0;
		while (str[n] == to_find[n] && str[n] != '\0')
		{
			n++;
			if (to_find[n] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
