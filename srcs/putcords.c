/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:13:15 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 16:44:28 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	putcords(t_fdf *fdf)
{
	t_point	**map;
	int		y;
	int		x;

	y = -1;
	map = fdf->map;
	while (++y < fdf->sizey)
	{
		x = -1;
		while (++x < fdf->sizex)
		{
			map[y][x].x = (double)(x * fdf->cell);
			map[y][x].y = (double)(y * fdf->cell);
		}
	}
}
