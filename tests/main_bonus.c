#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
	int fd01, fd02;
	char *line = NULL;

	fd01 = open("01_test_with_file", O_RDONLY);
	fd02 = open("02_test_with_file", O_RDONLY);

	//FD 01
	printf("\\First Line FD01\\\n");
	printf("%d\n", get_next_line(fd01, &line));
	printf("%s\n\n", line);
	free(line);

	//FD02
	printf("\\First Line FD02\\\n");
	printf("%d\n", get_next_line(fd02, &line));
	printf("%s\n\n", line);
	free(line);
}