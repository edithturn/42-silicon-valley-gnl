/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epuclla <epuclla@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:14:22 by epuclla           #+#    #+#             */
/*   Updated: 2020/06/07 18:47:30 by epuclla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/* BUFFER_SIZE <= 4000 bytes */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

# define FD_SIZE 256
# define NEVATIVE_VALUE -1
# define ZERO_VALUE 0
# define ONE_VALUE 1

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int	get_next_line(const int fd, char **line);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t n);
size_t	ft_strlen(const char *str);
int ft_memdel(void **ptr);
void	ft_strdel(char **as);

#endif