/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winresize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:52:25 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 19:44:01 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	winresize(int key, t_fdf *fdf)
{
	if (key == 27)
		fdf->hei -= 10;
	else if (key == 24)
		fdf->hei += 10;
	else if (key == 25)
		fdf->wid -= 10;
	else if (key == 29)
		fdf->wid += 10;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->data = NULL;
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->wid, fdf->hei, "hell");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->wid, fdf->wid);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
	&fdf->size_l, &fdf->end);
	mlx_key_hook(fdf->win_ptr, key_press, (void *)fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_close, (void *)0);
	celldraw(fdf, fdf->startx, fdf->starty);
}
