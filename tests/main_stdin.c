#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
	int ret;
	int line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;

	// Read on stdin
	printf("Please, enter your text:\n");
	while ((ret = get_next_line(0, &line)) > 0)
	{
		printf(" \n [ Return: %d ] | A line has been read #%d => %s\n", ret, line_count, line);
		line_count++;
		free(line);
	}

	if (ret == -1)
		printf("\n MAIN An error happened\n");
	else if (ret == 0)
		printf("\n MAIN EOF has been reached\n");

	return (0);
}