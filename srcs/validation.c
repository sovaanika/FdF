/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:58:02 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 17:01:18 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	validation(t_fdf *fdf, int fd)
{
	char	buf[10000];
	char	*res;
	int		count;
	char	*tmp;
	char	**arrn;

	res = ft_strnew(0);
	while ((count = read(fd, buf, 9999)) > 0)
	{
		buf[count] = '\0';
		tmp = res;
		res = ft_strjoin(res, buf);
		free(tmp);
	}
	arrn = ft_strsplit(res, '\n');
	mkmap(arrn, fdf);
	second_split(arrn, fdf);
	cleanarr(arrn);
	putcords(fdf);
	makestmap(fdf);
}

void	mkmap(char **arrn, t_fdf *fdf)
{
	t_point	**map;
	int		i;

	i = 0;
	while (arrn[i])
		i++;
	map = (t_point **)malloc((i + 1) * sizeof(**map));
	fdf->map = map;
	fdf->sizey = i;
}

void	second_split(char **arrn, t_fdf *fdf)
{
	char	**arrfin;
	char	**elem;
	int		y;
	int		x;
	t_point	**map;

	map = fdf->map;
	y = -1;
	while (arrn[++y])
	{
		x = -1;
		arrfin = ft_strsplit(arrn[y], ' ');
		check_size(arrfin, fdf, y);
		map[y] = (t_point *)malloc((fdf->sizex + 1) * sizeof(t_point));
		while (arrfin[++x])
		{
			elem = ft_strsplit(arrfin[x], ',');
			map[y][x].z = (double)(ft_atoi(elem[0]) * fdf->cell);
			map[y][x].color = ft_atoi_base(elem[1]);
			free(elem);
		}
	}
	cleanarr(arrfin);
}

void	check_size(char **arrfin, t_fdf *fdf, int i)
{
	int		j;

	j = 0;
	while (arrfin[j])
		j++;
	if (i != 0)
		if (j != fdf->sizex)
			ft_error(2);
	if (i == 0)
		fdf->sizex = j;
}

void	cleanarr(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
