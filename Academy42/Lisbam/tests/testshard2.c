/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshard2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:37:19 by gmartin-          #+#    #+#             */
/*   Updated: 2021/02/03 15:56:21 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

// int	ft_strcmp1(const char *s1, const char *s2)
// {
// 	while (*s1 && *s2)
// 		if (*s1++ != *s2++)
// 			return ((unsigned char)*--s1 - (unsigned char)*--s2);
// 	return ((unsigned char)*s1 - (unsigned char)*s2);
// }

// int main()
// {
//     //say_hi();
//     printf("len is %zd\n", ft_strlen("oyoyfff"));
//     char b[50] = "Je suis groot! hahahaha";
//     char a[] = "Julie neko desu";
//     ft_strcpy(b, a);
//     printf("b is = %s\n", b);
//     char c[100] = "the cake is a lie !\0I'm hidden lol\r\n";
//     char d[100] = "there are no stars in the sky";
//     printf("res of cmp is %d\n", ft_strcmp(c, d));
//     printf("res of cmp is %d\n", ft_strcmp1(c, d));
//     printf("res of cmp is %d\n", strcmp(c, d));
//     printf(" write amount is %zd\n", ft_write(1, "abcdefgh", 6));
//     printf(" write amount is %zd\n", write(1, "abcdefgh ", 6));
//     char *f = ft_strdup("oyo y");
//     printf("malloc is %s\n", f);
// }

void 	strcpyTest()
{
	char	d[50];
	printf("\n	-----  FT_STRCPY  -----\n\n");
	printf("1) <string> : %s\n", strcpy(d, ""));
	printf("1) <libasm> : %s\n", ft_strcpy(d, ""));
	printf("2) <string> : %s\n", strcpy(d, "Hello"));
	printf("2) <libasm> : %s\n", ft_strcpy(d, "Hello"));
	printf("3) <string> : %s\n", strcpy(d, "Assembly"));
	printf("3) <libasm> : %s\n", ft_strcpy(d, "Assembly"));
	printf("\n");
}

void 	strlenTest()
{
	printf("\n	-----  FT_STRLEN  -----\n\n");
	printf("1) <string> : %zu\n", strlen(""));
	printf("1) <libasm> : %zu\n", ft_strlen(""));
	printf("2) <string> : %zu\n", strlen("Hello"));
	printf("2) <libasm> : %zu\n", ft_strlen("Hello"));
	printf("3) <string> : %zu\n", strlen("\t"));
	printf("3) <libasm> : %zu\n", ft_strlen("\t"));
	printf("\n");
}

void 	strcmpTest()
{
	printf("\n	-----  FT_STRCMP  -----\n\n");
	printf("1) <string> : %d\n", strcmp("", ""));
	printf("1) <libasm> : %d\n", ft_strcmp("", ""));
	printf("2) <string> : %d\n", strcmp("Hello", "Hello"));
	printf("2) <libasm> : %d\n", ft_strcmp("Hello", "Hello"));
	printf("3) <string> : %d\n", strcmp("Assembly", ""));
	printf("3) <libasm> : %d\n", ft_strcmp("Assembly", ""));
	printf("4) <string> : %d\n", strcmp("", "Assembly"));
	printf("4) <libasm> : %d\n", ft_strcmp("", "Assembly"));
	printf("5) <string> : %d\n", strcmp("Nasm", "Assembly"));
	printf("5) <libasm> : %d\n", ft_strcmp("Nasm", "Assembly"));
	printf("\n");
}

void 	strdupTest()
{
	printf("\n	-----  FT_STRDUP  -----\n\n");
	printf("1) <stdlib> : %s\n", strdup(""));
	printf("1) <libasm> : %s\n", ft_strdup(""));
	printf("2) <stdlib> : %s\n", strdup("Hello"));
	printf("2) <libasm> : %s\n", ft_strdup("Hello"));
	printf("3) <stdlib> : %s\n", strdup("Assembly"));
	printf("3) <libasm> : %s\n", ft_strdup("Assembly"));
	printf("\n");
}

void 	writeTest()
{
	int		fd;
	char	b[50];

	printf("\n	-----  FT_WRITE  -----\n\n");
	printf("1) <unistd> : %zd\n", write(1, "", 0));
	printf("1) <libasm> : %zd\n", ft_write(1, "", 0));
	printf("2) <unistd> : %zd\n", write(1, "Hello", 2));
	printf("2) <libasm> : %zd\n", ft_write(1, "Hello", 2));
	printf("3) <unistd> : %zd\n", write(1, "Hello", 5));
	printf("3) <libasm> : %zd\n", ft_write(1, "Hello", 5));
	printf("4) <unistd> : %zd\n", write(1, "Hello", 10));
	printf("4) <libasm> : %zd\n", ft_write(1, "Hello", 10));
	printf("5) <unistd> : %zd\n", write(1, NULL, 10));
	printf("5) <libasm> : %zd\n", ft_write(1, NULL, 10));
	printf("6) <unistd> : %zd\n", write(0, "Hello", 5));
	printf("6) <libasm> : %zd\n", ft_write(0, "Hello", 5));
	printf("7) <unistd> : %zd\n", write(42, "Hello", 5));
	printf("7) <libasm> : %zd\n", ft_write(42, "Hello", 5));
	printf("8) <unistd> : %zd\n", write(-42, "Hello", 5));
	printf("8) <libasm> : %zd\n", ft_write(-42, "Hello", 5));

	printf("\n");

}

void 	readTest()
{
	int		fd;
	char	unistdBuffer[50];
	char	libasmBuffer[50];
	ssize_t	ret;

	printf("\n	-----  FT_READ    -----\n\n");

	// Existing file
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, unistdBuffer, 5);
	close(fd);
	printf("1) <unistd> : %zd\n", ret);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, libasmBuffer, 5);
	printf("1) <libasm> : %zd\n", ret);
	close(fd);


	// Non existing file
	fd = open("I don't exist", O_RDONLY);
	ret = read(fd, unistdBuffer, 5);
	close(fd);
	printf("2) <unistd> : %zd\n", ret);
	fd = open("I don't exist", O_RDONLY);
	ret = ft_read(fd, libasmBuffer, 5);
	printf("2) <libasm> : %zd\n", ret);
	close(fd);

	// NULL Buffer on existing file
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, NULL, 5);
	close(fd);
	printf("3) <unistd> : %zd\n", ret);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, NULL, 5);
	printf("3) <libasm> : %zd\n", ret);
	close(fd);

	// Empty File
	fd = open("emptyFile", O_RDONLY | O_CREAT | O_TRUNC, 0777);
	ret = read(fd, unistdBuffer, 5);
	printf("4) <unistd> : %zd\n", ret);
	fd = open("emptyFile", O_RDONLY | O_CREAT | O_TRUNC, 0777);
	ret = ft_read(fd, libasmBuffer, 5);
	printf("4) <libasm> : %zd\n", ret);
	close(fd);
	remove("emptyFile");

	printf("\n");
}

int main()
{
	strcpyTest();
	strlenTest();
	strcmpTest();
	strdupTest();
	writeTest();
	readTest();
	return 0;
}
