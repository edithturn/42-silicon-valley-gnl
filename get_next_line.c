/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epuclla <epuclla@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 00:26:39 by epuclla           #+#    #+#             */
/*   Updated: 2020/12/07 19:37:03 by epuclla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**Description: Write a function which returns
**a line read from a file descriptor, without the newline.
**Parameters:
**1. file descriptor for reading
**2. The value of what has been read
**Return value:
**1 : A line has been read
**0 : EOF has been reached
**-1 : An error happened
*/

char	*ft_strdup(const char *str)
{
	char	*new;
	ssize_t	i;

	new = ft_strnew(ft_strlen(str));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(ptr = (char *)malloc(ft_strlen(s1)
		+ ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE + (r = 1)];
	static char	*c_line = NULL;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	c_line == NULL ? c_line = ft_strnew(0) : NULL;
	while (!ft_strchr(c_line, '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(c_line, bf);
		ft_memdel((void **)&c_line);
		c_line = tmp;
	}
	if (r == 0)
		*line = ft_strdup(c_line);
	else if (r > 0)
		*line = ft_substr(c_line, 0, (ft_strchr(c_line, '\n') - c_line));
	else
		return (-1);
	tmp = ft_strdup(c_line + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	ft_memdel((void **)&c_line);
	c_line = tmp;
	return (r == 0 ? 0 * ft_memdel((void **)&c_line) : 1);
}
