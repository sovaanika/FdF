/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:15:32 by bbear             #+#    #+#             */
/*   Updated: 2019/02/07 17:20:50 by bbear            ###   ########.fr       */
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
	//map = (char **)malloc(120 * sizeof(char *));
	line = ft_strnew(0);
	tmp = line;

	while (get_next_line(fd, line))
	{
		temp = tmp;
		tmp = ft_strjoin(tmp, line);
		free(temp);
		i++;
	}
}

char	**doublesplit(char *line, int i)
{

}