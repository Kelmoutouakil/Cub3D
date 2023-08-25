/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:16 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/25 12:14:22 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int 	my_mlx_get_put(t_data data, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < data.w_tex && y >= 0 && y < data.h_tex)
	{
		dst = data.ad + (y * data.ln + x * (data.bit / 8));
		return(*(unsigned int *)dst);
	}
	return(0);
}

void	rays(t_data cub, int clr, int i)
{
	int		j;
	double	d;
	int		start;

	j = 0;
	cub.t[2] = ray_ver(cub,cub.t) * cos(cub.th - cub.ang);
	cub.t[5] = ray_hor(cub,cub.t) * cos(cub.th - cub.ang);
	d = dist_walls(cub, cub.t);
	start = (cub.h / 2) - (d / 2);
	cub.x_tex = (cub.t[0] -  ((int)(cub.t[0] / S_C) * S_C)) / S_C * cub.w_tex;
	cub.y_tex = 0;
	while (j < cub.h)
	{
		if (j >= start && j <= start + d)
		{
			clr = my_mlx_get_put(cub,cub.x_tex, cub.y_tex);
			cub.y_tex +=  cub.h_tex / d;
		}
		if (j > start + d)
			clr = 0xD2B48C;
		my_mlx_pixel_put(&cub, i, j, clr);
		j++;
	}
}

void	func_rays(t_data cub, int clr)
{
	int		i;
	double	angle_step;
	//printf("****** %d\n",cub.w);
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
