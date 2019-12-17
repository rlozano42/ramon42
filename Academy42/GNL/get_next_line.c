/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:01:56 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/16 19:58:07 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// Esta función libera el auxiliar pq estamos en el \0
static char				*ft_delete(char *aux)
{
	if (aux)
	{
		free(aux);
		aux = NULL;
	}
	return (aux);
}
// Por si los bytes leidos son 0 y la cadena esta vacia, ahí que devolver una cadena vacia
// Tambien si ha habido un error al leer el fd
static int				ft_return(char **line, int ret)
{
	if (ret < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}
// reviso la linea copiada en la auxiliar por si dentro de ella hay un \n o un \0, lo que sobra despues de un \n pues lo remeto en el aux y ret = 1 pq he leido algo.
// Si no hay \n puede haber \0 y por eso directamente en el line meto la frase y ret  = 0 pq hemos llegado al final por lo tanto libero el auxiliar y la apunto a null para
// saber que no hay nada dentro en la siguiente vuelta.
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
// Compruebo que no me trolean con los parametros, asigno el tamaño del buff que va a ser el buffersize cualquier problema devuelvo menos 1
// mientras los bytes leidos sean > 0 meto en el auxiliar la string que sea sino hay nada; si hay algo le hago join con lo anterior
// Si encuentro un \n en mi cadena me salgo del while, libero el buf, compruebo cualquier problema y voy metiendo en el auxiliar las strings
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
