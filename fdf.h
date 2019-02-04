#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			cellsize;
	int			color[3];
}				t_fdf;

typedef struct	s_bres
{
	int			sign[2];
	int			delta[2];
	int			error[2];
}				t_bres;

void			bresenham(t_fdf *fdf, int *x, int *y);
void			celldraw(t_fdf *fdf, int startx, int starty, int *size);
void			draw_y(t_fdf *fdf, int starty, int *x, int size);
void			draw_x(t_fdf *fdf, int startx, int *y, int size);


#endif