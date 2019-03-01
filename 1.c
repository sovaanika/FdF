/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:16:39 by bbear             #+#    #+#             */
/*   Updated: 2019/03/01 18:44:22 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 84)
	{
		rotate_x(fdf, 0.2618f);
	}
	else if (key == 91)
	{
		rotate_x(fdf, -0.2618f);
	}
	else if (key == 86)
	{
		rotate_y(fdf, 0.2618f);
	}
	else if (key == 88)
	{
		rotate_y(fdf, -0.2618f);
	}
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
		fdf->cell = 20;
		fdf->col[0] = 0x0000FFFF;
		fdf->col[1] = 0x00FF00FF;
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1700, 1700, "hell");
		validation(fdf, fd);
		celldraw(fdf, 400, 400);
		mlx_key_hook(fdf->win_ptr, key_press, (void *)fdf);
		mlx_hook(fdf->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_loop(fdf->mlx_ptr);
	}
}
