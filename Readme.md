## Get Next Line

The aim of this project is to make you code a function that returns a line
ending with a newline, read from a file descriptor.

This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming:
static variables.


## Compilation
```c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
```

## Compilation with main
```c
gcc main.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c
```
