/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:16:39 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 20:21:54 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 69 || key == 78)
	{
		key == 69 ? fdf->cellnew++ : fdf->cellnew--;
		resize(fdf);
	}
	else if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 91 || key == 84 || key == 88 || key == 86)
		prerotate(key, fdf);
	else if (key == 34 || key == 45 || key == 8)
		preprojection(key, fdf);
	else if (key == 125 || key == 126 || key == 123 || key == 124)
		move(key, fdf);
	else if (key == 27 || key == 24 || key == 25 || key == 29)
	{
		winresize(key, fdf);
		//draw(fdf);
	}
	return (0);
}

void	prerotate(int key, t_fdf *fdf)
{
	if (key == 91 || key == 84)
		key == 91 ? fdf->rot.x++ : fdf->rot.x--;
	else
		key == 88 ? fdf->rot.y++ : fdf->rot.y--;
	rotate(fdf, ANGLE);
}

void	preprojection(int key, t_fdf *fdf)
{
	if (key == 34)
		projection(1, fdf);
	else
		projection(key == 8 ? 2 : 0, fdf);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		fdf = (t_fdf *)malloc(sizeof(*fdf));
		fdf->mlx_ptr = mlx_init();
		fdf->cell = 5;
		fdf->cellnew = fdf->cell;
		fdf->rot.x = 0;
		fdf->rot.y = 0;
		fdf->hei = 1200;
		fdf->wid = 1200;
		fdf->startx = 500;
		fdf->starty = 500;
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->wid, fdf->hei, "hell");
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->wid, fdf->wid);
		fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
		&fdf->size_l, &fdf->end);
		validation(fdf, fd);
		celldraw(fdf, fdf->startx, fdf->starty);
		mlx_key_hook(fdf->win_ptr, key_press, (void *)fdf);
		mlx_hook(fdf->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_error(3);
}
