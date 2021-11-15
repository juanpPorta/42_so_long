/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:47 by jporta            #+#    #+#             */
/*   Updated: 2021/11/11 19:12:26 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

size_t	ft_getheight(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

size_t	ft_countlines(int fd)
{
	char	*line;
	size_t	h;
	size_t	w;
	size_t	aux;

	h = 0;
	line = get_next_line(fd);
	w = ft_strlen(line);
	if (ft_findchar(line, '\n'))
		w--;
	aux = w;
	while (line && ++h)
	{
		free (line);
		if (aux != w)
			return (0);
		line = get_next_line(fd);
		aux = ft_strlen(line);
		if (ft_findchar(line, '\n'))
			aux--;
	}
	if (h < 3 || w < 3 || h == w)
		return (0);
	return (h);
}

char	*ft_pickstr(char *str)
{
	char	*res;
	int		i;
	size_t	size;

	i = -1;
	size = ft_strlen(str);
	if (!ft_findchar(str, '\n'))
		size++;
	res = malloc(sizeof(char) * size);
	if (!res)
		return (0);
	size--;
	res[size] = '\0';
	while (++i < size)
		res[i] = str[i];
	return (res);
}

char	**ft_pickmap(int fd, size_t h)
{
	char	**mapa;
	char	*line;
	size_t	i;

	mapa = malloc(sizeof(char *) * (h + 1));
	if (!mapa)
		return (0);
	i = -1;
	line = get_next_line(fd);
	while (line && ++i < h)
	{
		mapa[i] = ft_pickstr(line);
		free (line);
		if (!mapa[i])
			return (0);
		line = get_next_line(fd);
	}
	mapa[h] = 0;
	return (mapa);
}

char	**ft_makemap(char const *fichero)
{
	char	**mapa;
	size_t	contlines;
	int		fd;

	fd = open(fichero, O_RDWR);
	if (fd < 0)
		return (0);
	contlines = ft_countlines(fd);
	close (fd);
	if (!contlines)
		return (0);
	fd = open(fichero, O_RDWR);
	if (fd < 0)
		return (0);
	mapa = ft_pickmap(fd, contlines);
	close (fd);
	return (mapa);
}
