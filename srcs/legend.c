/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:22:11 by bbear             #+#    #+#             */
/*   Updated: 2019/03/09 20:34:15 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	legend(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 16777215, "Move figure by arrows");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 35, 16777215, "Figure size +/-");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 50, 16777215, "Window size (/) and _/=");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 65, 16777215, "Figure rotation 8/2 and 4/6");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 16777215, "Projections:iso i, cabinet c, normal n");
	// mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 16777215
	// mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 16777215
	// mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 16777215
	// mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 16777215
}