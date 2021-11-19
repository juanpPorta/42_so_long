/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:29:18 by jporta            #+#    #+#             */
/*   Updated: 2021/11/19 17:56:31 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkfile(const char *fichero)
{
	int	i;

	i = -1;
	while (fichero[++i])
	{
		if (fichero[i] == '.' && fichero[i + 1] == 'b'
			&& fichero[i + 2] == 'e' && fichero[i + 3] == 'r')
			return (1);
	}
	return (0);
}

void	ft_init(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->x = 0;
	vars->map = NULL;
	vars->exit = 0;
	vars->C = 0;
	vars->count = 0;
}

int	main(int argc, const char **argv)
{
	t_vars	vars;
	int		i;
	size_t	w;
	size_t	h;

	i = 0;
	ft_init(&vars);
	if (argc != 2 || ft_checkfile(argv[1]) != 1)
		ft_error(1);
	vars.map = ft_makemap(argv[1]);
	if (!vars.map)
		ft_error(2);
	ft_checkingmap(vars);
	ft_checkobjs(&vars);
	w = ft_strlen(vars.map[0]) * TILE;
	h = ft_takesize(vars.map) * TILE;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "so_long");
	if (!vars.win)
		ft_error(2);
	ft_checkdraw(vars.map, &vars);
	mlx_hook(vars.win, 17, 1L << 17, cerrar, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
