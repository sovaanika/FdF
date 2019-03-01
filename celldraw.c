/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celldraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:26:25 by bbear             #+#    #+#             */
/*   Updated: 2019/02/28 19:14:40 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	celldraw(t_fdf *fdf, int startx, int starty)
{
	int		i;

	i = -1;
	while (++i < fdf->sizex)
		draw_y(fdf, starty, startx, i);
	i = -1;
	while (++i < fdf->sizey)
		draw_x(fdf, startx, starty, i);
}

void	draw_x(t_fdf *fdf, int startx, int starty, int y)
{
	int		x;
	double	xcord[2];
	double	ycord[2];

	ycord[1] = ycord[0];
	x = -1;
	while (++x < fdf->sizex - 1)
	{
		xcord[0] = (double)startx + fdf->map[y][x].x;
		xcord[1] = (double)startx + fdf->map[y][x + 1].x;
		ycord[0] = (double)starty + fdf->map[y][x].y;
		ycord[1] = (double)starty + fdf->map[y][x + 1].y;
		bresenham(fdf, xcord, ycord);
	}
}

void	draw_y(t_fdf *fdf, int starty, int startx, int x)
{
	int		y;
	double	xcord[2];
	double	ycord[2];

	y = -1;
	while (++y < fdf->sizey - 1)
	{
		ycord[0] = (double)starty + fdf->map[y][x].y;
		ycord[1] = (double)starty + fdf->map[y + 1][x].y;
		xcord[0] = (double)startx + fdf->map[y][x].x;
		xcord[1] = (double)startx + fdf->map[y + 1][x].x;
		bresenham(fdf, xcord, ycord);
	}
}
