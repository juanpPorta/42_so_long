/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:09:35 by jporta            #+#    #+#             */
/*   Updated: 2021/11/17 15:30:59 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	cerrar(int keycode, t_vars *vars)
{
	ft_free(vars);
	printf ("Done!\n");
	exit (EXIT_SUCCESS);
	return (0);
}
