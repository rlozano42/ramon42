/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <gmartin-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:37:19 by gmartin-          #+#    #+#             */
/*   Updated: 2020/05/22 14:10:54 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		test_ft_strdup()
{
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", strdup(""));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strdup(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'test'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", strdup("test"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strdup("test"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", strdup("0123456789"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strdup("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strdup(NULL));
}
void		test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;

	printf("\x1b[32mft_read:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"tests.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("tests.c", O_RDONLY);
	ret = read(fd, buffer, 0);
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 0));
	close(fd);
	fd = open("tests.c", O_RDONLY);
	ret = ft_read(fd, buffer, 0);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 0));
	close(fd);
	perror("ERROR");
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 50);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
	bzero(buffer, 100);
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	perror("ERROR");
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'open(\"testlib.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	bzero(buffer, 100);
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", ret);
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ret);
	close(fd);
	perror("ERROR");
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
	ret = read(42, buffer, 10);
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(42, buffer, 10);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	perror("ERROR");
	bzero(buffer, 100);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\x1b[0m\n");
	ret = read(fd, buffer, 10);
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void		test_ft_write()
{
	int			fd;
	char		buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(1, "", 0));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'test' '4'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(1, "test", 4));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(1, "test", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'test' '2'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(1, "test", 2));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(1, "test", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'test' '40'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(1, "test", 40));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(1, "test", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(1, NULL, 6));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(1, NULL, 6));
	perror("ERROR");
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'test' '4'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(0, "test", 4));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(0, "test", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'42' 'test' '4'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(42, "test", 4));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(42, "test", 4));
	perror("ERROR");
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'-1' 'test' '4'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %zd\n", write(-1, "test", 4));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %zd\n", ft_write(-1, "test", 4));
	perror("ERROR");
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> test' '15'\x1b[0m\n");
	write(fd, "MAQUINA test", 15);
	ft_write(fd, "MIOMIOM test", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", buffer);
	read(fd, buffer, 15);
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void		test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'test' 'test'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %d\n", strcmp("test", "test"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %d\n", ft_strcmp("test", "test"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'test' ''\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %d\n", strcmp("test", ""));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %d\n", ft_strcmp("test", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'test'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m %d\n", strcmp("", "test"));
	printf("		\x1b[33mMIOMIOM\x1b[0m %d\n", ft_strcmp("", "test"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'testtest' 'test'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %d\n", strcmp("testtest", "test"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %d\n", ft_strcmp("testtest", "test"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33mMIOMIOM\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'NULL' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mMIOMIOM\x1b[0m %d *mi retorno para evitar seg. fault\n", ft_strcmp(NULL, "bbonjour"));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'NULL' 'NULL'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mMIOMIOM\x1b[0m %d *mi retorno para evitar seg. fault\n", ft_strcmp(NULL, NULL));
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'' 'NULL'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mMIOMIOM\x1b[0m %d *mi retorno para evitar seg. fault\n", ft_strcmp("", NULL));
}

void		test_ft_strcpy()
{
	char	dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'test'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", strcpy(dst, "test"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strcpy(dst, "test"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strcpy(dst, "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", ft_strcpy(dst, NULL));
}

void		test_ft_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %lu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %lu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %lu\n", strlen("0123456789"));
	printf("		\x1b[33mMIOMIOM\x1b[0m  %lu\n", ft_strlen("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33mMAQUINA\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mMIOMIOM\x1b[0m  %s\n", "SEGMENTATION FAULT");
}

int			main(int argc, char *argv[])
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();

	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
		test_ft_write();
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
}
