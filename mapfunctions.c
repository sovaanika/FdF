/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:15:32 by bbear             #+#    #+#             */
/*   Updated: 2019/02/11 20:27:43 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_long_string(int fd, t_fdf *fdf)
{
	char	*line;
	int		i;
	char	*tmp;
	char	*temp;
	//char	**arrayz;
	t_point	**mp;
	t_map	*map;

	i = 0;
	map = (t_map *)malloc(sizeof(*map));
	mp = (t_point **)malloc(sizeof(**mp));
	map->map = mp;
	fdf->map = map;
	//fdf->map.map = mp;
	line = ft_strnew(0);
	tmp = line;
	while (get_next_line(fd, &line))
	{
		temp = tmp;
		tmp = ft_strjoin(tmp, line);
		free(temp);
		temp = tmp;
		tmp = ft_strjoin(tmp, "\n");
		free(temp);
		i++;
	}
	if (i == 0)
		ft_error(1);
	fdf->sizey = i;
	doublesplit(tmp, i, fdf);
	//return (arrayz);
}

void	doublesplit(char *line, int i, t_fdf *fdf)
{
	char	**farray;
	char	**finarray;
	char	**elems;
	int		j;
	int		count;
	int		k;
	t_point	**mp;

	count = 0;
	mp = fdf->map->map;
	farray = ft_strsplit(line, '\n');
	//finarray = (char **)malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j < i)
	{
		finarray = ft_strsplit(farray[j], ' ');
		k = 0;
		mp[k] = (t_point *)malloc((j + 1) * sizeof(*mp));
		while (*finarray)
		{
			elems = ft_strsplit(*finarray, ',');
			// fdf->map.map[k][j].z = elems[0];
			// fdf->map.map[k][j].color = elems[1];//абстрактные k, j
			mp[k][j].z = ft_atoi(elems[0]); //SEGFAULT HERE!!!
			mp[k][j].color = elems[1];
			k++;
		}
		j++;
	}
	fdf->sizex = k;
	fdf->map->map = mp;
	//finarray[j] = '\0';
	//return (finarray);
}

// void	check_length(t_fdf *fdf, char ***array, int i)
// {
// 	int		j;
// 	int		len;

// 	j = 1;
// 	fdf->sizey = i;
// 	len = ft_strlen(array[0]);
// 	while (j < i)
// 	{
// 		if (len != ft_strlen(array[j]))
// 			ft_error(2);
// 		j++;
// 	}
// 	fdf->sizex = len;
// }
