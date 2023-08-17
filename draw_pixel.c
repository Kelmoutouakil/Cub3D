/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:49:06 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/13 11:51:44 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_plyr(int x, int y, t_data cub, int clr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			my_mlx_pixel_put(&cub, x - 6 / 2 +i, y - 6/2 + j, clr);
			// mlx_pixel_put(cub.mlx, cub.mlx_win, x - 6 / 2 + i, y - 6 / 2 + j,
			// 	clr);
			j++;
		}
		i++;
	}
}

void	draw_carre(int x, int y, t_data cub)
{
	int i;
	int j;

	i = 1;
	while (i < S_C)
	{
		j = 1;
		while (j < S_C)
		{
			my_mlx_pixel_put(&cub, x * S_C +i, y * S_C + j, 0xffffff);
			// mlx_pixel_put(cub.mlx, cub.mlx_win, x * S_C + i, y * S_C + j,
			// 	0xffffff);
			j++;
		}
		i++;
	}
}