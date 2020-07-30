/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:55 by rlozano           #+#    #+#             */
/*   Updated: 2020/07/08 19:18:29 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <string.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		resolution_x;
	int		resolution_y;
	char	*no;

	argc = 1;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if ((line = ft_strchr(line, 'R')) != NULL)
		{
			line++;
			resolution_x = atoi(line);
			while (is_space(*line))
				line++;
			while (is_digit(*line))
				line++;
			resolution_y = atoi(line);
			printf("X = %d\nY = %d\n", resolution_x, resolution_y);
		}
/*		else if(*line == 'N' && *(line + 1) == 'O')
		{
			while (is_space(*line))
				line++;
			if (*line++ == '.' && *line == '/')
			{
				no = ft_strdup(line);	
			}
			printf("NO = %s\n", no);
		}*/
	}
}
