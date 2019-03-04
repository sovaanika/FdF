/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:16:39 by bbear             #+#    #+#             */
/*   Updated: 2019/03/04 19:18:18 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 91)
		rotate_x(fdf, M_PI / 12);
	else if (key == 84)
		rotate_x(fdf, -M_PI / 12);
	else if (key == 88)
		rotate_y(fdf, M_PI / 12);
	else if (key == 86)
		rotate_y(fdf, -M_PI / 12);
	return (0);
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
		//fdf->col[0] = 0x0000FFFF;
		//fdf->col[1] = 0x00FFFFFF;
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGTH, "hell");
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGTH);
		fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
		&fdf->size_l, &fdf->end);
		validation(fdf, fd);
		celldraw(fdf, 50, 50);
		mlx_key_hook(fdf->win_ptr, key_press, (void *)fdf);
		mlx_hook(fdf->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_loop(fdf->mlx_ptr);
	}
}
