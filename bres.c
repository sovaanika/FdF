// void	bresenham(t_fdf *fdf, double *x, double *y)
// {
// 	t_bres	data;

// 	data.delta[0] = fabs(x[1] - x[0]);
// 	data.delta[1] = fabs(y[1] - y[0]);
// 	data.sign[0] = x[0] < x[1] ? 1 : -1;
// 	data.sign[1] = y[0] < y[1] ? 1 : -1;
// 	data.error[0] = data.delta[0] - data.delta[1];
// 	while ((int)x[0] != (int)x[1] || (int)y[0] != (int)y[1])
// 	{
// 		fdf->color[2] = fdf->color[0] + (fdf->color[1] - fdf->color[0]);
// 		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x[0], y[0], fdf->color[2]);
// 		data.error[1] = data.error[0] * 2;
// 		if (data.error[1] > -(data.delta[1]) && (int)x[0] != (int)x[1])
// 		{
// 			data.error[0] -= data.delta[1];
// 			x[0] += data.sign[0];
// 		}
// 		if (data.error[1] < data.delta[0] && (int)y[0] != (int)y[1])
// 		{
// 			data.error[0] += data.delta[0];
// 			y[0] += data.sign[1];
// 		}
// 	}
// 	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x[1], y[1], fdf->color[1]);
// }