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
	// void	*mlx_ptr;
	// void	*win_ptr;
	t_fdf	*fdf;
	int		size[2];
	int		x[2];
	int		y[2];
	int		fd;

	x[0] = 153;
	x[1] = 53;
	y[0] = 70;
	y[1] = 70;
	fd = open("./test_maps/42.fdf", O_RDONLY);
	size[0] = 4;
	size[1] = 4;
	fdf = (t_fdf *)malloc(sizeof(*fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->cellsize = 250;
	fdf->color[0] = 0x0000FFFF;
	fdf->color[1] = 0x00FF00FF;
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1300, 1300, "hell");
	celldraw(fdf, 50, 50, size);
	mlx_key_hook(fdf->win_ptr, key_press, (void *)0);
	mlx_hook(fdf->win_ptr, 17, 0, close, (void *)0);
	mlx_loop(fdf->mlx_ptr);
}
//gcc -g 1.c bresenham.c celldraw.c -Ifdf.h -lmlx -framework OpenGL -framework AppKit