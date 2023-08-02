/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:37:34 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/01 15:39:55 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_ver(t_data *cub)
{
	int	tmp;

	int r_x, r_y, dx, dy, i, j;
	tmp = (int)(cub->p_x / S_C) * S_C;
	if (cub->th < M_PI / 2 || cub->th > 3 * M_PI / 2)
		r_x = tmp + S_C;
	else
		r_x = tmp;
	dx = fabs(r_x - cub->p_x);
	dy = fabs(dx / tan(cub->th));
	r_y = cub->p_y + dy;
	if (cub->th > M_PI)
		r_y = cub->p_y - dy;
	i = r_x / S_C;
	j = r_y / S_C;
	if (1)
		printf("i %d j %d\n", r_x, r_y);
	else
	{
		while (cub->p[i][j] != '1')
		{
			cub->p_x = r_x;
			r_x = r_x + S_C;
			dx = fabs(r_x - cub->p_x);
			dy = dx / tan(cub->th);
			r_y = r_y - dy;
			i = r_x / S_C;
			j = r_y / S_C;
		}
	}
}

void	ray_hor(t_data *cub)
{
	int r_x, r_y, dx, dy, i, j;
	int tmp;
	tmp = cub->p_y * S_C;
	tmp /= S_C;
	if (cub->th < M_PI && M_PI > 0)
	{
		r_y = tmp + S_C;
		dy = fabs(r_y - cub->p_y);
		dx = dy * tan(cub->th);
		r_x = cub->p_x - dx;
		i = r_x / S_C;
		j = r_y / S_C;
		if (cub->p[i][j] == '1')
			printf("there is a Wall\n");
		else
		{
			while (cub->p[i][j] != '1')
			{
				cub->p_y = r_y;
				r_y = r_y + S_C;
				dy = fabs(r_y - cub->p_y);
				dx = dy * tan(cub->th);
				r_x = r_x - dx;
				i = r_x / S_C;
				j = r_y / S_C;
			}
		}
	}
	else
	{
		r_y = tmp;
		dy = fabs(r_y - cub->p_y);
		dx = dy * tan(cub->th);
		r_x = cub->p_x - dx;
		i = r_x / S_C;
		j = r_y / S_C;
		if (cub->p[i][j] == '1')
			printf("there is a Wall\n");
		else
		{
			while (cub->p[i][j] != '1')
			{
				cub->p_y = r_y;
				r_y = r_y + S_C;
				dy = fabs(r_y - cub->p_y);
				dx = dy * tan(cub->th);
				r_x = r_x - dx;
				i = r_x / S_C;
				j = r_y / S_C;
			}
		}
	}
}