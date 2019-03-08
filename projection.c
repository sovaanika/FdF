/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 20:20:31 by bbear             #+#    #+#             */
/*   Updated: 2019/03/08 20:37:09 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(int type, t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	if (type == 1)
	{
		while (++y < fdf->sizey)
		{
			x = -1;
			while (++x < fdf->sizex)
			{
				fdf->map[y][x].x = (fdf->stmap[y][x].x - fdf->stmap[y][x].y) * cos(0.523599);
				fdf->map[y][x].y = -(fdf->stmap[y][x].z) + (fdf->stmap[y][x].x + fdf->stmap[y][x].y) * sin(0.523599);
				//fdf->map[y][x].z = fdf->stmap[y][x].z;
			}
		}
		draw(fdf);
	}
	else
	{
		fdf->rot.x = 0;
		fdf->rot.y = 0;
		rotate(fdf, ANGLE);
	}
}
