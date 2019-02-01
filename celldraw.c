/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celldraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:26:25 by bbear             #+#    #+#             */
/*   Updated: 2019/02/01 21:33:57 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	celldraw(t_fdf *fdf, int startx, int starty, int *size)
{
	int		i;
	int		x[2];
	int		y[2];

	i = 0;
	x[0] = startx + (fdf->cellsize);
	x[1] = x[0];
	y[0] = starty + (fdf->cellsize);
	y[1] = y[0];
	while (i++ < size[1])
	{
		draw_y(fdf, starty, x, size[0]);
		x[0] += fdf->cellsize;
		x[1] = x[0];
	}
	i = 0;
	x[0] = startx + (fdf->cellsize);
	x[1] = x[0];
	while (i++ < size[0])
	{
		draw_x(fdf, startx, y, size[1]);
		y[0] = y[0] + fdf->cellsize;
		y[1] = y[0];
	}
}

void	draw_x(t_fdf *fdf, int startx, int *y, int size)
{
	int		i;
	int		x[2];

	i = 0;
	while (i++ < size - 1)
	{
		x[0] = startx + i * (fdf->cellsize);
		x[1] = x[0] + fdf->cellsize;
		bresenham(fdf, x, y);
	}
}

void	draw_y(t_fdf *fdf, int starty, int *x, int size)
{
	int		j;
	int		y[2];

	j = 0;
	while (j++ < size - 1)
	{
		y[0] = starty + j * (fdf->cellsize);
		y[1] = y[0] + fdf->cellsize;
		bresenham(fdf, x, y);
	}
}