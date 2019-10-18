/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:37:54 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/16 11:15:23 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int n;
	int i;

	i = 0;
	n = 0;
	if (str[0] == '\0')
		i = 1;
	while (*str)
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
		{
			i = 1;
		}
		else
		{
			i = 0;
			return (i);
		}
		str++;
	}
	return (i);
}
