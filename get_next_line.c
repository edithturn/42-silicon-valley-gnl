/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epuclla <epuclla@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:39:49 by epuclla           #+#    #+#             */
/*   Updated: 2020/06/01 13:24:58 by epuclla          ###   ########.fr       */
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
	char				*buffer[BUFFER_SIZE + 1];
	static		char	*file_descriptor[FD_SIZE];
	char	*tmp;
	ssize_t	r;

	/* In case FD and Line will be NULL*/
	if(fd < 0 || !line)
		return (-1);
	
	while(r = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[r]='\0';
		tmp = file_descriptor[fd];
		file_descriptor[fd] = ft_strjoin(file_descriptor[fd], buffer);
		ft_memdel((void **)&tmp);
	}
	
/*validar linea*/

/*retornar value*/
	if (r == 0)
		r = 0;
	else
		r = 1;

return (r);
}