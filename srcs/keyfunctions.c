/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:24:27 by bbear             #+#    #+#             */
/*   Updated: 2019/03/10 15:24:57 by bbear            ###   ########.fr       */
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
		winresize(key, fdf);
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
