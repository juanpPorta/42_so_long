/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:28:06 by jporta            #+#    #+#             */
/*   Updated: 2021/11/19 17:56:19 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	set_player(t_vars *p, size_t y, size_t x)
{
	p->x = x;
	p->y = y;
}

int	ft_escape(t_vars *vars)
{
	if (vars->exit == vars->C)
	{
		ft_takedoor(vars);
		ft_printsquare(vars, vars->yD,
			vars->xD, "./sprites/puerta2.XPM");
		return (1);
	}
	return (0);
}

int	ft_checkobj(t_vars *vars)
{
	if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->exit += 1;
		vars->map[vars->y][vars->x] = '0';
	}
	if (ft_escape(vars) == 1)
	{
		ft_checkfin(vars);
		return (1);
	}
	return (0);
}

void	ft_checkmove(t_vars *vars, int numero)
{
	if (numero == 13 && (vars->map[vars->y][vars->x] == '1'
		|| (vars->map[vars->y][vars->x] == 'E'
		&& ft_checkobj(vars) == 0)))
		vars->y += 1;
	else if (numero == 1 && (vars->map[vars->y][vars->x] == '1'
		|| (vars->map[vars->y][vars->x] == 'E'
		&& ft_checkobj(vars) == 0)))
		vars->y -= 1;
	else if (numero == 0 && (vars->map[vars->y][vars->x] == '1'
		|| (vars->map[vars->y][vars->x] == 'E'
		&& ft_checkobj(vars) == 0)))
		vars->x += 1;
	else if (numero == 2 && (vars->map[vars->y][vars->x] == '1'
		|| (vars->map[vars->y][vars->x] == 'E'
		&& ft_checkobj(vars) == 0)))
		vars->x -= 1;
	ft_checkobj(vars);
}

void	ft_move(int numero, t_vars *vars)
{
	if (numero == 13 || numero == 1)
	{
		ft_printsquare(vars, vars->y,
			vars->x, "./sprites/fondo.XPM");
		if (numero == 13)
			vars->y -= 1;
		else if (numero == 1)
			vars->y += 1;
		ft_checkmove(vars, numero);
		ft_printsquare(vars, vars->y,
			vars->x, "./sprites/personaje1.XPM");
	}
	if (numero == 0 || numero == 2)
	{
		ft_printsquare(vars, vars->y,
			vars->x, "./sprites/fondo.XPM");
		if (numero == 0)
			vars->x -= 1;
		else if (numero == 2)
			vars->x += 1;
		ft_checkmove(vars, numero);
		ft_printsquare(vars, vars->y,
			vars->x, "./sprites/personaje1.XPM");
	}
}
