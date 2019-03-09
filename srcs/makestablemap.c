/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestablemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:19:10 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 16:45:27 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	makestmap(t_fdf *fdf)
{
	t_point	**stmap;
	int		y;
	int		x;

	y = -1;
	stmap = (t_point **)malloc((fdf->sizey + 1) * sizeof(**stmap));
	while (++y < fdf->sizey)
		stmap[y] = (t_point *)malloc((fdf->sizex + 1) * sizeof(t_point));
	y = -1;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			stmap[y][x].x = fdf->map[y][x].x;
			stmap[y][x].y = fdf->map[y][x].y;
			stmap[y][x].z = fdf->map[y][x].z;
		}
	}
	fdf->stmap = stmap;
}
