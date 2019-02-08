/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:15:32 by bbear             #+#    #+#             */
/*   Updated: 2019/02/08 17:31:21 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*make_long_string(t_fdf *fdf, char *str, int fd)
{
	char	*line;
	t_map	*mp;
	char	**map;
	int		i;
	char	*tmp;
	char	*temp;

	i = 0;
	mp = (t_map *)malloc(sizeof(*mp));
	line = ft_strnew(0);
	tmp = line;
	while (get_next_line(fd, line))
	{
		temp = tmp;
		tmp = ft_strjoin(tmp, line);
		free(temp);
		i++;
	}
	if (i == 0)
		ft_error(1);
}

char	***doublesplit(char *line, int i)
{
	char	**farray;
	char	***finarray;
	int		j;

	farray = ft_strsplit(line, '\n');
	finarray = (char ***)malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j <= i)
	{
		finarray[j] = ft_strsplit(farray[j], ' ');
		j++;
	}
	finarray[j] = '\0';
	return (finarray);
}