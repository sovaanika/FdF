/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:58:02 by bbear             #+#    #+#             */
/*   Updated: 2019/02/15 21:23:36 by bbear            ###   ########.fr       */
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
	while ((count = read(fd, buf, 128)) > 0)
	{
		buf[count] = '\0';
		tmp = res;
		res = ft_strjoin(res, buf);
		free(tmp);
	}
	arrn = ft_strsplit(res, '\n');
	int i = 0;
	while (i++ < 5)
		printf("%s\n", arrn[i]);
}

void	second_split(char **arrn, )