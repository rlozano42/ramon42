/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:36:43 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/12 11:55:31 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_int_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)i;
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

void	ft_bmp_header(t_gen *g, int fd, int ps)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (g->param.screenwidth * 3 * g->param.screenheight) +
		(ps * g->param.screenheight);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_int_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_int_char(header + 18, g->param.screenwidth);
	ft_int_char(header + 22, -g->param.screenheight);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
	write(fd, g->mlx.addr, g->param.screenwidth * g->param.screenheight * 4);
}

int		ft_screenshoot(t_gen *g)
{
	int				fd;
	int				padsize;

	padsize = (4 - (g->param.screenwidth * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777 |
		O_TRUNC | O_APPEND)) < 0)
		return (0);
	ft_bmp_header(g, fd, padsize);
	close(fd);
	exit(0);
	return (1);
}
