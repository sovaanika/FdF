/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:57:00 by bbear             #+#    #+#             */
/*   Updated: 2019/02/03 17:00:51 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *fdf, int *x, int *y)
{
	t_bres	data;

	data.delta[0] = abs(x[1] - x[0]);
	data.delta[1] = abs(y[1] - y[0]);
	data.sign[0] = x[0] < x[1] ? 1 : -1;
	data.sign[1] = y[0] < y[1] ? 1 : -1;
	data.error[0] = data.delta[0] - data.delta[1];
	while (x[0] != x[1] || y[0] != y[1])
	{
		fdf->color[2] = fdf->color[0] + (fdf->color[1] - fdf->color[0]);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x[0], y[0], fdf->color[2]);
		data.error[1] = data.error[0] * 2;
		if (data.error[1] > -(data.delta[1]))
		{
			data.error[0] -= data.delta[1];
			x[0] += data.sign[0];
		}
		if (data.error[1] < data.delta[0])
		{
			data.error[0] += data.delta[0];
			y[0] += data.sign[1];
		}
	}
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x[1], y[1], fdf->color[1]);
}
