#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

int		key_press(int key, void *param)
{
	if (key == 53 || key == 17)
		exit(EXIT_SUCCESS);
	return (0);
}

int		close(void *param)
{
	exit(0);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x[2];
	int		y[2];

	x[0] = 1053;
	x[1] = 500;
	y[0] = 1070;
	y[1] = 70;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1300, 1300, "hell");
	bresenham(mlx_ptr, win_ptr, x, y);
	mlx_key_hook(win_ptr, key_press, (void *)0);
	mlx_hook(win_ptr, 17, 0, close, (void *)0);
	mlx_loop(mlx_ptr);
}
