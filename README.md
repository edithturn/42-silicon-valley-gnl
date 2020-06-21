# Get Next Line (GNL)  :tractor:


The aim of this project is to make you code a function that **returns a line
ending with a newline, read from a file descriptor.**

This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming:
**"static variables"**

### Function Prototype
```c
int	get_next_line(int fd, char **line);
```
### Compilation

**GNL Mandatory Part**

Your program must compile with the flag -D **BUFFER_SIZE=xx**. which will be used
as the buffer size for the read calls in your get_next_line.

Make sure that your function behaves well when it reads from a file and when it
reads from the standard input.

 :point_right: Locate in the **42-silicon-valley-libft/test** folder.

**GNL with files**
```bash
gcc main.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c  -I ../

./a.out files/part1_test01_with_lines
```

**GNL with standard input (stdin)**
```bash
gcc main_stdin.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c -I ../

./a.out
```

**GNL Bonus Part**
```bash
gcc main_bonus.c -g -Wall -Wextra -Werror -D BUFFER_SIZE=1 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c -I ../

./a.out
```

### Points to understand in GNL

According to our GNL subject *Calling your function get_next_line in a loop will then allow you to read the text
available on a file descriptor one line at a time until the EOF*

Our GNL call seen from the main:

```c
int main(int argc, char **argv)
{
	int fd, ret, line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf(" \n [ Return: %d ] | A line has been read #%d => %s\n", ret, line_count, line);
			line_count++;
			free(line);
		}
		printf(" \n [ Return: %d ] A line has been read #%d: %s\n", ret, line_count++, line);
		printf("\n");
		if (ret == -1)
			printf("-----------\n An error happened\n");
		else if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
			free(line);
		}
		close(fd);
	}
```

This next line will return an integer that will be used as a parameter for the **get_next_line** function.
```c
fd = open(argv[1], O_RDONLY);
```
**get_next_line** function will return an integer that will be taken to evaluate all the lines until the file ends.

### Return value
 | Value | Description         |
 |-----------|----------------------|
 |  1 | A line has been read |
 |  0 | EOF has been reached |
 |  -1 | An error happened |

### READ function

```c
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
```
**Input parameters:**
- **int fd** file descriptor is an integer and not a file pointer. The file descriptor for stdin is 0
- **void *buf** pointer to buffer to store characters read by the read function
- **size_t count** maximum number of characters to read

:traffic_light: Note.: a character is equivalent to a 1 byte and a byte is made up of 8 bits therefore a character is made up of 8 bits (1 byte)

We can do something like this to read 20 bytes or 20 characters:
```c
char buffer[20];
read(fd, buffer, 20);
```

:traffic_light: Note.: remember read() doesn't add '\0' to terminate to make it string (just gives raw buffer).


### Funciones Utiliizadas

**External Functions**

  | Function | Description         |
 |-----------|----------------------|
 |  read | A line has been read |
 |  malloc | EOF has been reached |
 |  free | An error happened |

**Util Functions**

 | Function | Description         |
 |-----------|----------------------|
 |  ft_strnew() | A line has been read |
 |  ft_strchr() | EOF has been reached |
 |  ft_strjoin | An error happened |
 |  ft_memdel() | A line has been read |
 |  ft_strdup() | EOF has been reached |
 |  ft_substr | An error happened |
 |  ft_strlen | An error happened |


## TESTERS

### 42TESTERS-GNL
 :point_right: Locate in the **42-silicon-valley-gnl** folder. 

```bash
gt clone https://github.com/Mazoise/42TESTERS-GNL.git
cd 42TESTERS-GNL
./all_tests.sh
./all_tests_with_bonus.sh
```

### Valgrind

**Installation**
```bash
sudo apt-get update -y
sudo apt-get install -y valgrind
```
**How to Use?**
```bash
gcc main.c -g -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c -I ../

valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out files/part1_test01_with_lines
```
![alt text](img/valgrind_output.png)

### Fsanitize

```bash
gcc main.c -g3 -fsanitize=address -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c -I ../

./a.out files/part1_test01_with_lines
```
![alt text](img/fsanitize_output.png)


## Debug with lldb and GUI
```bash
gcc -g main.c -Wall -Wextra -Werror -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c -I ../
lldb a.out
b get_next_line
run files/part1_test01_with_lines
gui
```
![alt text](img/lldb_gui.png)

**keys to move**

- tab : change window
- s : next line
- directional key : variables navigation
- h : help

## References

https://valgrind.org/docs/manual/quick-start.html


### Norminette

Use and install this repository: 
- [ Norminette ](https://github.com/42sp/norminette-client.git)

```bash
norminette *.*
```