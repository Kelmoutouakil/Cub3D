/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:16 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 00:19:29 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_point p1, t_point p2, t_data cub, int clr)
{
	float	dx;
	float	dy;
	int		steps;
	float	xincrement;
	float	yincrement;
	float	x;
	float	y;
	int		i;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
	{
		steps = fabs(dx);
	}
	else
	{
		steps = fabs(dy);
	}
	if (steps == 0)
		return ;
	xincrement = dx / (float)steps;
	yincrement = dy / (float)steps;
	x = p1.x;
	y = p1.y;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(&cub, x, y, clr);
		x += xincrement;
		y += yincrement;
		i++;
	}
}

void	rays(t_data cub, double *t, int clr,int i)
{
	t[2] = ray_ver(cub, t);
	t[5] = ray_hor(cub, t);
	double d = dist_walls(cub);
	int ii = 0;
	int w_s = (cub.h / 2) - (d / 2);
	while(ii < (int)d)
	{
		my_mlx_pixel_put(&cub, i, w_s, clr);
		w_s++;
		ii++;
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
		rays((cub), cub.t, clr,i);
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
