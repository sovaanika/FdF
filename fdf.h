#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <stdio.h> //DELETE AFTER COMPLITION!!!

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	char		*color;
}				t_point;

// typedef struct	s_map
// {

// 	int			size[2];
// }				t_map;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			cellsize;
	int			color[3];
	int			sizex;
	int			sizey;
	t_point		**map;
	//t_map		*map;
}				t_fdf;

typedef struct	s_bres
{
	int			sign[2];
	int			delta[2];
	int			error[2];
}				t_bres;

void			bresenham(t_fdf *fdf, int *x, int *y);
void			celldraw(t_fdf *fdf, int startx, int starty);
void			draw_y(t_fdf *fdf, int starty, int *x, int size);
void			draw_x(t_fdf *fdf, int startx, int *y, int size);
void			ft_error(int nb);
//void			make_long_string(int fd, t_fdf *fdf);
//void			doublesplit(char *line, int i, t_fdf *fdf);
//void			check_length(t_fdf *fdf, char ***array, int i);
void			validation(t_fdf *fdf, int fd);


#endif