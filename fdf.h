#ifndef FDF_H
# define FDF_H

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			cellsize;
}				t_fdf;

void			bresenham(t_fdf *fdf, int *x, int *y);
void			celldraw(t_fdf *fdf, int startx, int starty, int *size);
void			draw_y(t_fdf *fdf, int starty, int *x, int size);
void			draw_x(t_fdf *fdf, int startx, int *y, int size);


#endif