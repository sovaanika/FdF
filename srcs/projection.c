/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 20:20:31 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 16:45:07 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	projection(int type, t_fdf *fdf)
{
	if (type == 1)
		isoproj(fdf);
	else if (type == 2)
		cabinproj(fdf);
	else
	{
		fdf->rot.x = 0;
		fdf->rot.y = 0;
		rotate(fdf, ANGLE);
	}
}

void	isoproj(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			fdf->map[y][x].x = (fdf->stmap[y][x].x - fdf->stmap[y][x].y)
			* cos(0.523599);
			fdf->map[y][x].y = -(fdf->stmap[y][x].z) + (fdf->stmap[y][x].x
			+ fdf->stmap[y][x].y) * sin(0.523599);
			fdf->map[y][x].z = fdf->stmap[y][x].z;
		}
	}
	draw(fdf);
}

void	cabinproj(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			fdf->map[y][x].x = (fdf->stmap[y][x].x - fdf->stmap[y][x].z)
			* cos(M_PI / 4) * 1.415;
			fdf->map[y][x].y = (fdf->stmap[y][x].y - fdf->stmap[y][x].z)
			* cos(M_PI / 4) * 1.415;
			fdf->map[y][x].z = fdf->stmap[y][x].z;
		}
	}
	draw(fdf);
}
