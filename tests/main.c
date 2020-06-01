#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
	int fd; //all file descirptor is represented by 
	char *line;
	int ret;

	//open the file in read only mode
	fd = open("test", O_RDONLY);

	// iterate the 
	while((ret = get_next_line(fd, &line)) > 0)
	{
		printf("return=%d, line=%s\n", ret, line);
		free(line);
	}

	// Always print the end of the file
	printf("return=%d, line=%s\n", ret, line);
	free(line);

	return(0);
}