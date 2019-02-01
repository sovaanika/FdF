/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:57:00 by bbear             #+#    #+#             */
/*   Updated: 2019/02/01 20:36:31 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

void	bresenham(t_fdf *fdf, int *x, int *y)
{
	int		delta[2];
	int		sign[2];
	int		error[2];
	int		color[3];
	float	i;
	float	plus;

	color[0] = 0x0000FF00;
	color[1] = 0x000000FF;
	delta[0] = abs(x[1] - x[0]);
	delta[1] = abs(y[1] - y[0]);
	sign[0] = x[0] < x[1] ? 1 : -1;
	if (delta[0] > delta[1])
		i = (float)1 / (delta[0] + 1);
	else
		i = (float)1 / (delta[1] + 1);
	plus = i;
	sign[1] = y[0] < y[1] ? 1 : -1;
	error[0] = delta[0] - delta[1];
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x[1], y[1], color[0]);
	while (x[0] != x[1] || y[0] != y[1])
	{
		color[2] = color[0] + i * (color[1] - color[0]);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x[0], y[0], color[2]);
		error[1] = error[0] * 2;
		if (error[1] > -delta[1])
		{
			error[0] -= delta[1];
			x[0] += sign[0];
		}
		if (error[1] < delta[0])
		{
			error[0] += delta[0];
			y[0] += sign[1];
		}
		i += plus;
	}
}