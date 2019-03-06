/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:40:16 by bbear             #+#    #+#             */
/*   Updated: 2019/03/06 14:49:31 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			if (fdf->cellnew > fdf->cell)
			{
				fdf->stmap[y][x].x = fdf->stmap[y][x].x * 1.1;//+= x * (fdf->cellnew - fdf->cell);
				fdf->stmap[y][x].y = fdf->stmap[y][x].y * 1.1;//+= y * (fdf->cellnew - fdf->cell);
				fdf->stmap[y][x].z = fdf->stmap[y][x].z * 1.1;//+= (fdf->cellnew - fdf->cell);
			}
			else if (fdf->cellnew < fdf->cell)
			{
				fdf->stmap[y][x].x = fdf->stmap[y][x].x * 0.9;
				fdf->stmap[y][x].y = fdf->stmap[y][x].y * 0.9;
				fdf->stmap[y][x].z = fdf->stmap[y][x].z * 0.9;
			}
		}
	}
	fdf->cell = fdf->cellnew;
	rotate(fdf, ANGLE);
}
