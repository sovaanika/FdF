#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <stdio.h> //DELETE AFTER COMPLETION!!!

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	char		*color;
}				t_point;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			cellsize;
	int			color[3];
	int			sizex;
	int			sizey;
	t_point		**map;
}				t_fdf;

typedef struct	s_bres
{
	int			sign[2];
	double		delta[2];
	double		error[2];
}				t_bres;

void			bresenham(t_fdf *fdf, double *x, double *y);
void			celldraw(t_fdf *fdf, int startx, int starty);
void			draw_y(t_fdf *fdf, int starty, int startx, int x);
void			draw_x(t_fdf *fdf, int startx, int starty, int y);
void			ft_error(int nb);
void			validation(t_fdf *fdf, int fd);
void			mkmap(char **arrn, t_fdf *fdf);
void			second_split(char **arrn, t_fdf *fdf);
void			check_size(char **arrfin, t_fdf *fdf, int i);
void			cleanarr(char **array);
void			putcords(t_fdf *fdf);
void			rotate_x(t_fdf *fdf, double angle);
void			draw(t_fdf *fdf);
void			rotate_y(t_fdf *fdf, double angle);

#endif