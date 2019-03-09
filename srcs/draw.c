/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:24:23 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 20:30:40 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw(t_fdf *fdf)
{
	int		x;
	int		y;

	x = -1;
	while (++x < fdf->wid)
	{
		y = -1;
		while (++y < fdf->hei)
		{
			fdf->data[y * fdf->wid + x] = 0;
		}
	}
	celldraw(fdf, fdf->startx, fdf->starty);
	legend(fdf);
}
