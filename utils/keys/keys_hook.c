/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:30:19 by jporta            #+#    #+#             */
/*   Updated: 2021/11/16 14:18:54 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_free(vars);
		printf("Done!\n");
		exit(1);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1
		|| keycode == 2)
	{
		vars->count += 1;
		printf("movimientos: %d\n", vars->count);
		ft_move(keycode, vars);
	}
	return (0);
}
