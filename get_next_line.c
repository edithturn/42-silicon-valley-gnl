/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epuclla <epuclla@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:39:49 by epuclla           #+#    #+#             */
/*   Updated: 2020/06/07 18:56:55 by epuclla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Description: Write a function which returns a line read from a
file descriptor, without the newline.
**Parameters:
**#1. file descriptor for reading
**#2. The value of what has been read
**Return value:
**1 : A line has been read
**0 : EOF has been reached
**-1 : An error happened
*/


#include "get_next_line.h"
#include <stdio.h>

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}

char	*ft_strnew(size_t size){
		return (ft_memalloc((size + 1 ) * sizeof(char)));
}

void	*ft_memalloc(size_t size)
{
		void	*ptr;
		ptr = malloc(size);
		if(ptr == NULL)
			return (NULL);
		ft_memset(ptr, 0, size);
		return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*ub;

	ub = (unsigned char *)b;
	while (len > 0)
	{
		*ub = c;
		len--;
		ub++;
	}
	return (b);
}

int ft_memdel(void **ptr)
{
	if(*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	//ssize_t to indicate  type signed (-1 example)
	char				buffer[BUFFER_SIZE + 1];
	static		char	*current_line[FD_SIZE];
	char	*tmp;
	ssize_t	r;

	printf(" =>1 %s\n", current_line[fd]);
	if(fd < 0 || (!current_line[fd] && !(current_line[fd] = ft_strnew(0))))
	{
		printf("%s\n", "NEVATIVE_VALUE");
		return (NEVATIVE_VALUE);
	}
	printf(" =>2 %s\n", current_line[fd]);
	while(!ft_strchr(current_line[fd], '\n') && (r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r]='\0';
		tmp = current_line[fd];
		current_line[fd] = ft_strjoin(current_line[fd], buffer);
		ft_memdel((void **)&tmp);
	}
	if (r == NEVATIVE_VALUE)
		return (NEVATIVE_VALUE);
	else if (r > ZERO_VALUE)
	{
		printf("%s", "r > 0");
		*line = ft_substr(current_line[fd], 0,  ft_strchr(current_line[fd], '\n') - current_line[fd]);
	}
	else // alloca memoria para cada linea
		*line = ft_strdup(current_line[fd]);

	current_line[fd] = ft_strdup(current_line[fd] + (ft_strlen(*line) + 1));
	ft_memdel((void **)&tmp);

	if(r == ZERO_VALUE)
		return ZERO_VALUE;
	else
		return ONE_VALUE;
}