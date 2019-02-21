/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:16:39 by bbear             #+#    #+#             */
/*   Updated: 2019/02/21 18:34:37 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		fdf = (t_fdf *)malloc(sizeof(*fdf));
		fdf->mlx_ptr = mlx_init();
		fdf->cellsize = 50;
		fdf->color[0] = 0x0000FFFF;
		fdf->color[1] = 0x00FF00FF;
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1300, 1300, "hell");
		validation(fdf, fd);
		celldraw(fdf, 50, 50);
		mlx_key_hook(fdf->win_ptr, key_press, (void *)0);
		mlx_hook(fdf->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_loop(fdf->mlx_ptr);
	}
}
//gcc -g 1.c bresenham.c error.c celldraw.c mapfunctions.c -Ifdf.h -lmlx -framework OpenGL -framework AppKit

//gcc -g 1.c bresenham.c celldraw.c mapfunctions.c error.c ./libft/ft_strnew.c ./libft/ft_strsplit.c ./libft/ft_strjoin.c ./libft/get_next_line.c ./libft/ft_atoi.c ./libft/ft_memalloc.c ./libft/ft_putendl.c ./libft/ft_strchr.c ./libft/ft_strlen.c ./libft/ft_strsub.c ./libft/ft_bzero.c ./libft/ft_putchar.c ./libft/ft_putstr.c -Ifdf.h -lmlx -framework OpenGL -framework AppKit