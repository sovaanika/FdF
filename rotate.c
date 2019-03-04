/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:09:05 by bbear             #+#    #+#             */
/*   Updated: 2019/03/04 20:31:54 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_fdf *fdf, double angle)
{
	t_point	**map;
	int		x;
	int		y;
	double	sy;

	map = fdf->map;
	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			sy = fdf->stmap[y][x].y;
			fdf->map[y][x].y = (sy - (fdf->sizey * fdf->cell) / 2) * cos(angle)
			- fdf->stmap[y][x].z * sin(angle) + (fdf->sizey * fdf->cell) / 2;
			fdf->map[y][x].z = (sy - (fdf->sizey * fdf->cell) / 2) * sin(angle)
			+ fdf->stmap[y][x].z * cos(angle);
		}
	}
	draw(fdf);
}

void	rotate_y(t_fdf *fdf, double angle)
{
	t_point	**map;
	int		x;
	int		y;
	double	sx;

	map = fdf->map;
	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			sx = fdf->stmap[y][x].x;
			map[y][x].y = map[y][x].y;
			fdf->map[y][x].x = (sx - (fdf->sizex * fdf->cell) / 2) * cos(angle)
			+ fdf->stmap[y][x].z * sin(angle) + (fdf->sizex * fdf->cell) / 2;
			fdf->map[y][x].z = -1 * ((sx - (fdf->sizex * fdf->cell) / 2)
			* sin(angle)) + fdf->stmap[y][x].z * cos(angle);
		}
	}
	draw(fdf);
}
