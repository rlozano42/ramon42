/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:02:27 by rlozano           #+#    #+#             */
/*   Updated: 2019/11/25 18:16:06 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char             *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *ptr;
    size_t mal;
    size_t count;
    size_t start2;

    start2 = start;
    count = 0;
    mal = len - start;
        if (len == 0)
        return (0);
        if (s == NULL)
            return (0);
    if (!(ptr = malloc((sizeof(char) * (len)) + 1)))
        return(0);

    while (start < (len + start2))
    {
        ptr[count] = s[start];
        start++;
        count ++;
    }
    ptr[count] = '\0';
    return(ptr);
}

int main()
{
	char *str = "i just want this part #############";
	size_t size = 20;
	char *ret = ft_substr(str, 5, size);
	printf("%s",ret);
}
