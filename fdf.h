/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:04:34 by bbear             #+#    #+#             */
/*   Updated: 2019/03/08 20:28:07 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <stdio.h> //DELETE AFTER COMPLETION!!!
# define WIDTH 1500
# define HEIGTH 1500
# define ANGLE M_PI / 12

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_rotate
{
	int			x;
	int			y;
}				t_rotate;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			end;
	int			cell;
	int			cellnew;
	int			col[3];
	int			sizex;
	int			sizey;
	double		sx;
	t_point		**map;
	t_point		**stmap;
	t_rotate	rot;
}				t_fdf;

typedef struct	s_bres
{
	double		delta[2];
	double		xi;
	double		yi;
	double		d;
	double		y;
	double		x;
}				t_bres;

void			bresenham(t_fdf *fdf, double *x, double *y, int color);
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
void			plotlinelow(double *xc, double *yc, t_fdf *fdf, int color);
void			plotlinehigh(double *xc, double *yc, t_fdf *fdf, int color);
double			*ft_swap(double *param);
void			makestmap(t_fdf *fdf);
int				ft_atoi_base(const char *str);
void			rotate(t_fdf *fdf, double angle);
void			resize(t_fdf *fdf);
void			projection(int type, t_fdf *fdf);

#endif
