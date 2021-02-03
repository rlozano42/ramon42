/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <gmartin-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:37:19 by gmartin-          #+#    #+#             */
/*   Updated: 2020/05/28 11:55:32 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>


int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char * dst, const char * src);
char	 	*ft_strdup(const char *src);
size_t		ft_strlen(const char *str);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);

#endif
