/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:08:25 by jporta            #+#    #+#             */
/*   Updated: 2021/11/11 18:49:33 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_printsquare(t_vars *vars, size_t y, size_t x, char *imgname)
{
	void		*img;
	int			tile;
	size_t		o;
	size_t		j;

	tile = TILE;
	o = (tile * y);
	j = (tile * x);
	img = mlx_xpm_file_to_image(vars->mlx, imgname, &tile, &tile);
	mlx_put_image_to_window(vars->mlx, vars->win, img, j, o);
	mlx_destroy_image(vars->mlx, img);
}

void	ft_checkdraw(char **map, t_vars *vars)
{
	size_t		j;
	size_t		o;

	j = -1;
	o = -1;
	while (++o < ft_takesize(map))
	{
		while (++j < ft_strlen(map[0]))
		{
			if (map[o][j] == '1')
				ft_printsquare(vars, o, j, "./sprites/bloque.XPM");
			if (map[o][j] == 'P')
			{
				ft_printsquare(vars, o, j, "./sprites/personaje1.XPM");
				set_player(vars, o, j);
			}
			if (map[o][j] == 'C')
				ft_printsquare(vars, o, j, "./sprites/pineaple.XPM");
			if (map[o][j] == 'E')
				ft_printsquare(vars, o, j, "./sprites/puerta1.XPM");
			if (map[o][j] == '0')
				ft_printsquare(vars, o, j, "./sprites/fondo.XPM");
		}
		j = -1;
	}
}
