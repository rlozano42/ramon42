/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:28:05 by rlozano           #+#    #+#             */
/*   Updated: 2020/07/07 12:36:19 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>


int		get_next_line(int fd, char **line);
size_t		ft_strlen_gnl(const char *str);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strdup_gnl(const char *s);
char		*ft_strjoin_gnl(char *s1, char *s2);

#endif
