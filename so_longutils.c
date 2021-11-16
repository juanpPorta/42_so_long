/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:42:14 by jporta            #+#    #+#             */
/*   Updated: 2021/11/16 14:33:29 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkeys(t_vars *vars)
{
	size_t		j;
	size_t		o;

	j = -1;
	o = -1;
	while (++o < ft_takesize(vars->map))
	{
		while (++j < ft_strlen(vars->map[0]))
		{
			if (vars->map[o][j] != '1' && vars->map[o][j] != 'P'
			 && vars->map[o][j] != 'C' && vars->map[o][j] != 'E'
			 && vars->map[o][j] != '0')
				ft_error (2);
		}
		j = -1;
	}
}

void	ft_checkobjs(t_vars *vars)
{
	size_t		j;
	size_t		o;
	size_t		p;
	size_t		E;

	j = -1;
	o = -1;
	p = 0;
	E = 0;
	while (++o < ft_takesize(vars->map))
	{
		while (++j < ft_strlen(vars->map[0]))
		{
			if (vars->map[o][j] == 'P')
				p += 1;
			if (vars->map[o][j] == 'C')
				vars->C += 1;
			if (vars->map[o][j] == 'E')
				E += 1;
		}
		j = -1;
	}
	if (p <= 0 || vars->C <= 0 || E <= 0)
		ft_error(2);
	ft_checkeys(vars);
}

size_t	ft_takesize(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
