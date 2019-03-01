/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:57:00 by bbear             #+#    #+#             */
/*   Updated: 2019/03/01 18:18:25 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plotlinelow(double *xc, double *yc, t_fdf *fdf)
{
	t_bres	data;

	data.delta[0] = xc[1] - xc[0];
	data.delta[1] = yc[1] - yc[0];
	data.yi = 1;
	if (data.delta[1] < 0)
	{
		data.yi = -1;
		data.delta[1] = -1 * (data.delta[1]);
	}
	data.d = 2 * data.delta[1] - data.delta[0];
	data.y = yc[0];
	data.x = xc[0];
	while (data.x <= xc[1] && data.x >= xc[0])
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, data.x, data.y, fdf->col[1]);
		if (data.d > 0)
		{
			data.y = data.y + data.yi;
			data.d = data.d - 2 * data.delta[0];
		}
		data.d = data.d + 2 * data.delta[1];
		data.x++;
	}
}

void	plotlinehigh(double *xc, double *yc, t_fdf *fdf)
{
	t_bres	data;

	data.delta[0] = xc[1] - xc[0];
	data.delta[1] = yc[1] - yc[0];
	data.xi = 1;
	if (data.delta[0] < 0)
	{
		data.xi = -1;
		data.delta[0] = -1 * data.delta[0];
	}
	data.d = 2 * data.delta[0] - data.delta[1];
	data.x = xc[0];
	data.y = yc[0];
	while (data.y <= yc[1] && data.y >= yc[0])
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, data.x, data.y, fdf->col[1]);
		if (data.d > 0)
		{
			data.x = data.x + data.xi;
			data.d = data.d - 2 * data.delta[1];
		}
		data.d = data.d + 2 * data.delta[0];
		data.y++;
	}
}

double	*ft_swap(double *param)
{
	double	tmp;

	tmp = param[0];
	param[0] = param[1];
	param[1] = tmp;
	return (param);
}

void	bresenham(t_fdf *fdf, double *x, double *y)
{
	if (fabs(y[1] - y[0]) < fabs(x[1] - x[0]))
		if (x[0] > x[1])
			plotlinelow(ft_swap(x), ft_swap(y), fdf);
		else
			plotlinelow(x, y, fdf);
	else
	{
		if (y[0] > y[1])
			plotlinehigh(ft_swap(x), ft_swap(y), fdf);
		else
			plotlinehigh(x, y, fdf);
	}
}
