#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"
int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;
	int 	i;
	line = 0;
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while ((ret = get_next_line(fd, &buff)) > 0)
			{
				printf("\033[1;31m[Return: %d] \033[1;34mLine #%d: \033[0;32m%s\033[0m\n", ret, ++line, buff);
				free(buff);
			}
			if (ret == -1)
				printf("\033[1;31m-----------\nError\033[0m\n");
			else if (ret == 0)
			{
				printf("\033[1;31m[Return: %d] \033[1;34mLine #%d: \033[0;32m%s\033[0m\n", ret, ++line, buff);
				printf("\033[0;31m-----------\nEnd of file\033[0m\n");
			}
			else
				printf("\033[1;31m[Return: %d] \033[1;34mLine #%d: \033[0;32m%s\033[0m\n", ret, ++line, buff);
			close(fd);
		}
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("\033[1;31m[Return: %d] \033[1;34mLine #%d: \033[0;32m%s\033[0m\n", ret, ++line, buff);
		if (ret == -1)
			printf("\033[1;31m-----------\nError\033[0m\n");
		else if (ret == 0)
		{
			printf("\033[1;31m[Return: %d] \033[1;34mLine #%d: \033[0;32m%s\033[0m\n", ret, ++line, buff);
			printf("\033-----------\nEnd of stdin\033[0m\n");
		}
		close(fd);
	}
	return (0);
}


