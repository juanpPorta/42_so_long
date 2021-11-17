/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objetos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:03:57 by jporta            #+#    #+#             */
/*   Updated: 2021/11/17 15:27:23 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_checkfin(t_vars *vars)
{
	if (vars->map[vars->y][vars->x] == vars->map[vars->yD][vars->xD])
	{
		ft_free(vars);
		printf ("Done!\n");
		exit (1);
	}
}

void	ft_takedoor(t_vars *vars)
{
	size_t		j;
	size_t		o;

	j = -1;
	o = -1;
	while (++o < ft_takesize(vars->map))
	{
		while (++j < ft_strlen(vars->map[0]))
		{
			if (vars->map[o][j] == 'E')
			{
				vars->xD = j;
				vars->yD = o;
			}	
		}
		j = -1;
	}
}
