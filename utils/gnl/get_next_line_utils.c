/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:48:04 by jporta            #+#    #+#             */
/*   Updated: 2021/11/09 17:11:21 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *cadena)
{
	size_t	a;

	a = 0;
	if (cadena == NULL)
		return (0);
	while (cadena[a])
		a++;
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	cont;
	size_t	a;

	a = start;
	cont = 0;
	if (!s)
		return (0);
	cont = 0;
	while (cont < len && s[a++])
		cont++;
	substr = (char *)malloc(cont + 1);
	if (!substr)
		return (0);
	a = start;
	cont = 0;
	while (cont < len && a < ft_strlen(s))
		substr[cont++] = s[a++];
	substr[cont] = '\0';
	return (substr);
}

char	*join_modif(char **saved, int fd, ssize_t nr_bytes, char *buf)
{
	char	*temp;

	temp = ft_strjoin(saved[fd], buf);
	if (saved[fd])
	{
		free(saved[fd]);
		saved[fd] = NULL;
	}
	saved[fd] = temp;
	if (nr_bytes < 0)
	{
		if (saved[fd])
		{
			free(saved[fd]);
			saved[fd] = NULL;
		}
	}
	return (saved[fd]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		cont;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	cont = 0;
	while (s2[cont] != '\0')
	{
		str[i] = s2[cont];
		cont++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
