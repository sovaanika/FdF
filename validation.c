/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:58:02 by bbear             #+#    #+#             */
/*   Updated: 2019/02/21 18:34:13 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validation(t_fdf *fdf, int fd)
{
	char	buf[128];
	char	*res;
	int		count;
	char	*tmp;
	char	**arrn;

	res = ft_strnew(0);
	while ((count = read(fd, buf, 127)) > 0)
	{
		buf[count] = '\0';
		tmp = res;
		res = ft_strjoin(res, buf);
		free(tmp);
	}
	arrn = ft_strsplit(res, '\n');
	mkmap(arrn, fdf);
	second_split(arrn, fdf);
	// int i = 0;
	// while (i++ < 5)
	// 	printf("%s\n", arrn[i]);
}

void	mkmap(char **arrn, t_fdf *fdf)
{
	t_point	**map;
	int		i;

	i = 0;
	while (arrn[i])
		i++;
	map = (t_point **)malloc(i * sizeof(**map));
	fdf->map = map;
	fdf->sizey = i;
}

void	second_split(char **arrn, t_fdf *fdf)
{
	char	**arrfin;
	char	**elem;
	int		i;
	int		j;
	t_point	**map;

	map = fdf->map;
	i = 0;
	while (arrn[i])
	{
		j = 0;
		arrfin = ft_strsplit(arrn[i], ' ');
		check_size(arrfin, fdf, i);
		map[i] = (t_point *)malloc((fdf->sizex) * sizeof(*map));
		while (arrfin[j])
		{
			elem = ft_strsplit(arrfin[j], ',');
			fdf->map[i][j].z = ft_atoi(elem[0]);
			fdf->map[i][j].color = elem[1];
			free(elem);
			j++;
		}
		i++;
	}
	fdf->map = map;
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