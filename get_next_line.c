/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epuclla <epuclla@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:39:49 by epuclla           #+#    #+#             */
/*   Updated: 2020/06/12 02:15:35 by epuclla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
**Description: Write a function which returns a line read from a file descriptor, without the newline.
**Parameters:
**1. file descriptor for reading
**2. The value of what has been read
**Return value:
**1 : A line has been read
**0 : EOF has been reached
**-1 : An error happened
*/

int		get_next_line(int fd, char **line)
{
	char					buffer[BUFFER_SIZE + 1];
	static		char		*current_line = NULL;
	char					*tmp;
	ssize_t					r;
	int 						remaining;

	if(fd < 0 || !line || BUFFER_SIZE <= 0)
			return (-1);
	if(current_line == NULL)
		current_line = ft_strnew(0);
	r = read(fd, buffer, BUFFER_SIZE);
	while(!ft_strchr(current_line, '\n') && (r > 0))
	{
		printf("READED BITS %zu\n", r);
		buffer[r]='\0';
		tmp = current_line;
		current_line = ft_strjoin(current_line, buffer);
		ft_memdel((void **)&tmp);
	}
	if (r == -1)
		return (-1);
	else if (r > 0)
	{
		remaining = ft_strchr(current_line, '\n') - current_line;
		*line = ft_substr(current_line, 0, remaining);
	}
	else
		*line = ft_strdup(current_line);
	//move the pointer to the second line
	current_line = ft_strdup(current_line + (ft_strlen(*line) + 1));
	ft_memdel((void **)&tmp);

	return (r == 0 ? 0 : 1);
}