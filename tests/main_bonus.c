#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
	int fd01, fd02, fd03;
	char *line = NULL;

	fd01 = open("files/bonus_test01_with_lines", O_RDONLY);
	fd02 = open("files/bonus_test02_with_lines", O_RDONLY);
	fd03 = open("files/bonus_test03_with_lines", O_RDONLY);

	//FD 01
	printf("FD01 | First Line | FD return %d\n", get_next_line(fd01, &line));
	printf("%s\n\n", line);
	free(line);

	//FD02
	printf("FD02 | First Line | FD return %d\n", get_next_line(fd02, &line));
	printf("%s\n\n", line);
	free(line);

	//FD03
	printf("FD03 | First Line | FD return %d\n", get_next_line(fd03, &line));
	printf("%s\n\n", line);
	free(line);

	//FD01 Seconda Line
	printf("FD01 | Second Line | FD return %d\n", get_next_line(fd01, &line));
	printf("%s\n\n", line);
	free(line);

	//FD03 Second Line
	printf("FD03 | Second Line | FD return %d\n", get_next_line(fd03, &line));
	printf("%s\n\n", line);
	free(line);
	printf("FD03 | Third Line | FD return %d\n", get_next_line(fd03, &line));
	printf("%s\n\n", line);
	free(line);
}
