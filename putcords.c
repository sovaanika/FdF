/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:13:15 by bbear             #+#    #+#             */
/*   Updated: 2019/02/26 18:37:41 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putcords(t_fdf *fdf)
{
	t_point	**map;
	int		i;
	int		j;

	i = -1;
	map = fdf->map;
	while (map[++i])
	{
		j = 0;
		while (map[i][j].z)
		{
			map[i][j].x = (double)(j * fdf->cellsize);
			map[i][j].y = (double)(i * fdf->cellsize);
			j++;
		}
	}
	fdf->map = map;
}
