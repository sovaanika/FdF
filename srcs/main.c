/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:16:39 by bbear             #+#    #+#             */
/*   Updated: 2019/03/10 15:26:53 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	makedata(t_fdf *fdf)
{
	fdf->cell = 5;
	fdf->cellnew = fdf->cell;
	fdf->rot.x = 0;
	fdf->rot.y = 0;
	fdf->hei = 1200;
	fdf->wid = 1200;
	fdf->startx = 500;
	fdf->starty = 500;
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
		makedata(fdf);
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->wid, fdf->hei, "fdf");
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->wid, fdf->wid);
		fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
		&fdf->size_l, &fdf->end);
		validation(fdf, fd);
		draw(fdf);
		mlx_key_hook(fdf->win_ptr, key_press, (void *)fdf);
		mlx_hook(fdf->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_error(3);
}
