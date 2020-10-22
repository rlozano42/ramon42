/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:08:35 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/14 19:22:40 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char		*ft_delete(char *aux) // Si existe aux libero y vacio el aux que no apunta a nada
{
	if (aux)
	{
		free(aux);
		aux = NULL;
	}
	return (aux);
}

static int	ft_return(int ret, char **line)
{
	if (ret < 0) // Para que devuelva menos 1 por que el read ha dado menos 1 pq ahi un error
		return (-1);
	*line = ft_strdup(""); // sino devuelvo una  cadena vacia y decuelvo cero que he llegado al final
	return (0);
}

// Para ver si tengo un \n entre 
static char		*ft_print(char  *aux, char **line, int *ret)
{
	char	*temp;
	int		pos;

	pos = 0;
	while (aux[pos] != '\n' && aux[pos] != '\0') // recorro hasta que encuentroun \n o un \0  
		pos++;
	if (aux[pos] == '\n')  // si es \n 
	{
		*line = ft_substr(aux, 0, pos); // Busco la cadena hasta el /n y lo introduzco en el line
		temp = ft_strdup(aux + (pos + 1)); 
		free(aux);
		aux = temp; // ft_swap
		if (aux[0] == '\0') //si lo siguiente ya es un \0 lo mando a que me diga que ya es el final
			aux = ft_delete(aux);
		*ret = 1; // Porque hay algo en el fd
	}
	else
	{
		*line = ft_strdup(aux); // Copio en el line el aux
		free(aux); // libero
		aux = NULL; // y el auxiliar no apunta a nada
		*ret = 0; // hemos llegado al final
	}
	return (aux); // Devuelvo el aux
}

// funcion principal
int get_next_line(int fd, char **line)
{
	static char		*aux[4096];
	int				ret;
	char			*buf;
	//por si me trolean con los datos de parametro
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	// Asigno valor al buff del buffersize que voy a meter y lo protejo 
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	// siempre que el ret sea mayor que 0 
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// finalizo la string buf
		buf[ret] = '\0';
		if (aux[fd] == NULL)
			aux[fd] = ft_strdup(buf); // Llenar por primera vez el auxiliar
		else
			aux[fd] = ft_strjoin(aux[fd], buf); // Unir el buffer y el auxiliar hasta que haya un \n
		if (ft_strchr(aux[fd], '\n')) //Si hay un barra n se cierra eel while
			break;
	}
	free(buf); // libero el buffer ya lo he volcado todo al aux
	if ((ret < 0) || (ret == 0 && aux[fd] == NULL )) // si el ret es -1 && si el ret = 0 y no hay nada en la cadena
		return (ft_return(ret, line));
	aux[fd] = ft_print(aux[fd], line, &ret); // aux le mando el line, el aux y la direccion de ret  para modificar en la función .
	return (ret);
}
