/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:35 by jporta            #+#    #+#             */
/*   Updated: 2021/11/15 18:45:55 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include "./utils/gnl/get_next_line.h"
# ifndef TILE
#  define TILE 32
# endif

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	size_t		x;
	size_t		y;
	size_t		xD;
	size_t		yD;
	size_t		exit;
	size_t		C;
	int			count;
}		t_vars;

/* so_long.c */
int		main(int argc, const char **argv);
size_t	ft_takesize(char **map);
/*map*/
char	**ft_makemap(char const *fichero);
char	**ft_pickmap(int fd, size_t h);
char	*ft_pickstr(char *str);
size_t	ft_countlines(int fd);
size_t	ft_findchar(char *str, char c);
void	ft_checkingmap(t_vars vars);
void	ft_printsquare(t_vars *vars, size_t j, size_t o, char *imgname);
void	ft_checkdraw(char **map, t_vars *vars);
void	set_player(t_vars *p, size_t y, size_t x);
/* control */
int		cerrar(int keycode, t_vars *vars);
void	ft_error(int error);
void	ft_free(t_vars vars);
int		key_hook(int keycode, t_vars *vars);
void	ft_move(int numero, t_vars *vars);
void	getPlayerPosition(size_t o, size_t j);
void	ft_takedoor(t_vars *vars);
void	ft_checkfin(t_vars *vars);
void	ft_checkmove(t_vars *vars, int numero);
void	ft_checkobjs(t_vars *vars);
void	ft_free(t_vars vars);
#endif