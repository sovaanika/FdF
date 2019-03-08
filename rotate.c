/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:09:05 by bbear             #+#    #+#             */
/*   Updated: 2019/03/08 20:10:55 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf, double angle)
{
	rotate_y(fdf, angle * (fdf->rot.y % 24));
	rotate_x(fdf, angle * (fdf->rot.x % 24));
	draw(fdf);
}

void	rotate_x(t_fdf *fdf, double angle)
{
	int		x;
	int		y;
	double	sy;

	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			//fdf->map[y][x].x = fdf->stmap[y][x].x;
			sy = fdf->stmap[y][x].y;
			fdf->map[y][x].y = (sy - (fdf->sizey * fdf->cell) / 2) * cos(angle)
			- fdf->map[y][x].z * sin(angle) + (fdf->sizey * fdf->cell) / 2;
			fdf->map[y][x].z = (sy - (fdf->sizey * fdf->cell) / 2) * sin(angle)
			+ fdf->map[y][x].z * cos(angle);
		}
	}
}

void	rotate_y(t_fdf *fdf, double angle)
{
	int		x;
	int		y;
	double	sx;

	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			fdf->map[y][x].y = fdf->stmap[y][x].y;
			sx = fdf->stmap[y][x].x;
			fdf->map[y][x].x = (sx - (fdf->sizex * fdf->cell) / 2) * cos(angle)
			+ fdf->stmap[y][x].z * sin(angle) + (fdf->sizex * fdf->cell) / 2;
			fdf->map[y][x].z = -1 * ((sx - (fdf->sizex * fdf->cell) / 2)
			* sin(angle)) + fdf->stmap[y][x].z * cos(angle);
		}
	}
}
