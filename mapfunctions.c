/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:15:32 by bbear             #+#    #+#             */
/*   Updated: 2019/02/05 19:24:43 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	makemap(t_fdf *fdf, char *str, int fd)
{
	char	**line;
	t_map	*mp;
	char	**map;
	int		i;

	i = 0;
	mp = (t_map *)malloc(sizeof(*mp));
	map = (char ***)malloc(120 * sizeof(char *));
	line = NULL;
	while (get_next_line(fd, line))
	{
		map[i] = ft_strsplit(line, ' ');
		i++;

	}
}