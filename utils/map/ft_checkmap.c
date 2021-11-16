/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:56 by jporta            #+#    #+#             */
/*   Updated: 2021/11/16 13:49:54 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		printf("error de argumentos\n");
		exit (EXIT_SUCCESS);
	}
	if (error == 2)
	{
		printf("mapa no valido\n");
		exit (EXIT_SUCCESS);
	}
}

void	ft_checkingmap(t_vars vars)
{
	int	i;
	int	a;

	if (vars.map)
	{
		i = -1;
		while (vars.map[++i] && vars.map[i + 1])
		{
			a = -1;
			while (vars.map[0][++a])
			{
				if (vars.map[0][a] != '1')
					ft_error (2);
			}
			while (vars.map[i][0] != '1' || vars.map[i]
				[ft_strlen(vars.map[i]) - 1] != '1')
				ft_error (2);
		}
		a = -1;
		while (vars.map[i][++a])
		{
			if (vars.map[i][a] != '1')
				ft_error (2);
		}
	}
}
