/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:37:34 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/02 12:40:48 by kelmouto         ###   ########.fr       */
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
	dy = fabs(dx * tan(cub->th));
	r_y = cub->p_y + dy;
	if (cub->th > M_PI)
		r_y = fabs(cub->p_y - dy);
	dy = fabs(S_C * tan(cub->th));
	if (cub->th > M_PI)
		dy *= -1;
	dx = S_C;
	if (cub->th < 3 * M_PI / 2 && cub->th > M_PI / 2)
		dx *= -1;
	i = r_x / S_C;
	j = r_y / S_C;
	while (i > 0 && i < (ft_strlen(cub->p[0])) && (j > 0 && j < (int)(cub->h
				/ S_C)) && cub->p[j][i] != '1')
	{
		r_x += dx;
		r_y += dy;
		i = r_x / S_C;
		j = r_y / S_C;
	}
}

void	ray_hor(t_data *cub)
{
	int	tmp;

	int r_x, r_y, dx, dy, i, j;
	tmp = (int)(cub->p_y / S_C) * S_C;
	r_y = tmp;
	if (cub->th < M_PI)
		r_y = tmp + S_C;
	dy = fabs(r_y - cub->p_y);
	dx = fabs(dy / tan(cub->th));
	r_x = cub->p_x + dx;
	if (cub->th < 3 * M_PI / 2)
		r_y = fabs(cub->p_x - dx);
	dx = fabs(S_C / tan(cub->th));
	if (cub->th < 3 * M_PI / 2)
		dy *= -1;
	dy = S_C;
	if (cub->th > M_PI && cub->th < 2 * M_PI)
		dy *= -1;
	i = r_x / S_C;
	j = r_y / S_C;
	while (i > 0 && i < (ft_strlen(cub->p[0])) && (j > 0 && j < (int)(cub->h
				/ S_C)) && cub->p[j][i] != '1')
	{
		r_x += dx;
		r_y += dy;
		i = r_x / S_C;
		j = r_y / S_C;
	}
	printf("x : %d y %d\n", r_x, r_y);
}
