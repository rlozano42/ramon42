/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:33:04 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/16 17:33:18 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char				*ft_delete(char *aux)
{
	if (aux)
	{
		free(aux);
		aux = NULL;
	}
	return (aux);
}

static int				ft_return(char **line, int ret)
{
	if (ret < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

static char				*ft_print(char **line, char *aux, int *ret)
{
	int		count;
	char	*temp;

	count = 0;
	while (aux[count] != '\n' && aux[count] != '\0')
		count++;
	if (aux[count] == '\n')
	{
		*line = ft_substr(aux, 0, count);
		temp = ft_strdup(aux + (count + 1));
		free(aux);
		aux = temp;
		if (aux[0] == '\0')
			aux = ft_delete(aux);
		*ret = 1;
	}
	else
	{
		*line = ft_strdup(aux);
		free(aux);
		aux = NULL;
		*ret = 0;
	}
	return (aux);
}

int						get_next_line(int fd, char **line)
{
	static char	*aux[4096];
	char		*buf;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (aux[fd] == NULL)
			aux[fd] = ft_strdup(buf);
		else
			aux[fd] = ft_strjoin(aux[fd], buf);
		if (ft_strchr(aux[fd], '\n'))
			break ;
	}
	free(buf);
	if ((ret < 0) || (aux[fd] == NULL && ret == 0))
		return (ft_return(line, ret));
	aux[fd] = ft_print(line, aux[fd], &ret);
	return (ret);
}
