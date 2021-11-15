/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:53:32 by jporta            #+#    #+#             */
/*   Updated: 2021/10/26 17:30:53 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s_dup;

	s_dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!s_dup)
		return (0);
	ft_memcpy(s_dup, s1, ft_strlen(s1) + 1);
	return (s_dup);
}

char	*my_line(char **saved, int fd, char *buf)
{
	int		len;
	char	*line;
	char	*rst;

	free(buf);
	len = 0;
	while (saved[fd][len] != '\n')
		len++;
	line = 0;
	line = ft_substr(saved[fd], 0, len + 1);
	rst = ft_strdup(&(saved[fd][len + 1]));
	free(saved[fd]);
	saved[fd] = ft_strdup(rst);
	free (rst);
	return (line);
}

int	its_a_line(char **saved, int fd)
{
	int	len;

	len = 0;
	while (saved[fd][len] != '\0')
	{
		if (saved[fd][len] == '\n')
			return (1);
		len++;
	}
	return (0);
}

char	*get_my_line(int fd, ssize_t nr_bytes, char **saved, char *buf)
{
	char	*hello;

	hello = 0;
	while (nr_bytes > 0)
	{
		if (its_a_line(saved, fd))
			return (my_line(saved, fd, buf));
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		buf[nr_bytes] = '\0';
		if (its_a_line(saved, fd) == 0 && nr_bytes == 0)
		{
			hello = ft_strdup(saved[fd]);
			free(saved[fd]);
			saved[fd] = NULL;
			free(buf);
			if (ft_strlen(hello) == 0)
			{
				free(hello);
				return (NULL);
			}
			return (hello);
		}
		saved[fd] = join_modif(saved, fd, nr_bytes, buf);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{	
	ssize_t				nr_bytes;
	static char			*saved[4096];
	char				*buf;

	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
	{
		free (buf);
		return (NULL);
	}
	if (!saved[fd])
		saved[fd] = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!saved[fd])
		return (NULL);
	nr_bytes = BUFFER_SIZE;
	return (get_my_line(fd, nr_bytes, saved, buf));
}
