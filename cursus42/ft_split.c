/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:03:25 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/29 20:41:39 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char    *ft_malloc(char const *s, char c)
{
    char *aux;
    int count;

    count = 0;
    while (s[count] != c)
        count++;
    if (!(aux = malloc(sizeof(char)* (count) + 1)))
            return (0); 
    return (aux);
}

char    *ft_letras(char const *s, char c)
{
    char *aux;
    int n;

    n = 0;
    aux = ft_malloc(s,c);

    while (s[n] != c)
    {
        aux[n] = s[n];
        n++;
    }
    aux[n] = '\0';
    return (aux);
}*/
int		countword(char const *s, char c)
{
//	int strl_count;
	int count;

	count = 0;	
	s = ft_strtrim(s,(char *)c);
//	strl_count = ft_strlen(s);
	while (s[count])
	{
		if (s[count] != c)
			count++;
	}
	return ();
}


char	*ft_split(char const *s, char c)
{
    char *aux;

    aux = ft_letras(s,c);
    return (aux);
}

int main()
{
    char *s = "HOla julian te quiero+ ";
    printf("%s", ft_split(s, ' '));
}
