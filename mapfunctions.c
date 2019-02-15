/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:15:32 by bbear             #+#    #+#             */
/*   Updated: 2019/02/14 17:31:29 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_long_string(int fd, t_fdf *fdf)
{
	char	*line;
	int		i;
	char	*tmp;
	char	*temp;
	t_point	**mp;

	i = 0;
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
	fdf->sizex = i;
	mp = (t_point **)malloc(i * sizeof(**mp));
	fdf->map = mp;
	doublesplit(tmp, i, fdf);
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

	mp = fdf->map;
	farray = ft_strsplit(line, '\n');
	j = 0;
	while (j < i)
	{
		count = 0;
		finarray = ft_split_whitespaces(farray[j]);
		while (finarray[count])
			count++;
		k = 0;
		mp[j] = (t_point *)malloc((count + 1) * sizeof(*mp));
		while (*finarray)
		{
			elems = ft_strsplit(*finarray, ',');
			fdf->map[j][k].z = ft_atoi(elems[0]);
			fdf->map[j][k].color = elems[1];//k == x, j == y
			k++;
			finarray++;
		}
		j++;
	}
	fdf->sizey = k;
	fdf->map = mp;
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
