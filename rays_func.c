/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:16 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 17:04:33 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rays(t_data cub, int clr, int i)
{
	int		j;
	double	d;
	int		start;

	j = 0;
	// printf("%f %f %f\n",  cos(fabs(cub.th - cub.ang)), cub.ang, cub.th);
	cub.t[2] = ray_ver(cub) * cos(cub.th - cub.ang);
	cub.t[5] = ray_hor(cub) * cos(cub.th - cub.ang);
	d = dist_walls(cub);
	start = (cub.h / 2) - (d / 2);
	while (j < cub.h)
	{
		my_mlx_pixel_put(&cub, i, j, clr);
		if (j >= start && j <= start + d)
			clr = 0x696969f;
		if (j > start + d)
			clr = 0xD2B48C;
		j++;
	}
}

void	func_rays(t_data cub, int clr)
{
	int		i;
	double	angle_step;

	angle_step = (M_PI / 3) / cub.w;
	i = 0;
	while (i < cub.w / 2)
	{
		cub.th -= angle_step;
		if (cub.th < 0)
			cub.th = 2 * M_PI;
		i++;
	}
	i = 0;
	while (i < cub.w)
	{
		rays(cub, clr, i);
		cub.th += angle_step;
		if (cub.th > 2 * M_PI)
			cub.th = 0;
		i++;
	}
}

int	ft_check_a(t_data *cub)
{
	int	k;
	int	s;
	int	e;
	int	f;

	k = (int)((cub->p_x - cos(cub->th + M_PI / 2) * S_P - 3) / S_C);
	s = (int)((cub->p_y - sin(cub->th + M_PI / 2) * S_P - 3) / S_C);
	e = (int)((cub->p_x - cos(cub->th + M_PI / 2) * S_P + 3) / S_C);
	f = (int)((cub->p_y - sin(cub->th + M_PI / 2) * S_P + 3) / S_C);
	if (cub->p[s][k] != '1' && cub->p[f][e] != '1')
		return (1);
	return (0);
}

int	ft_check_d(t_data *cub)
{
	int	k;
	int	s;
	int	e;
	int	f;

	k = (int)((cub->p_x + cos(cub->th + M_PI / 2) * S_P - 3) / S_C);
	s = (int)((cub->p_y + sin(cub->th + M_PI / 2) * S_P - 3) / S_C);
	e = (int)((cub->p_x + cos(cub->th + M_PI / 2) * S_P + 3) / S_C);
	f = (int)((cub->p_y + sin(cub->th + M_PI / 2) * S_P + 3) / S_C);
	if (cub->p[s][k] != '1' && cub->p[f][e] != '1')
		return (1);
	return (0);
}
