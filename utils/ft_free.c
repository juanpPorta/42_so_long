/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:18:18 by jporta            #+#    #+#             */
/*   Updated: 2021/11/09 18:23:23 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_vars vars)
{
	int	i;

	if (vars.map)
	{
		i = -1;
		while (vars.map[++i])
			free(vars.map[i]);
		free(vars.map);
	}
	if (vars.mlx && vars.win)
	{
		mlx_clear_window(vars.mlx, vars.win);
		mlx_destroy_window(vars.mlx, vars.win);
	}
}
