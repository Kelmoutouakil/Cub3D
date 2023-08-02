/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:45:12 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/02 16:03:49 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_wall1(t_data *cub)
{
	int	k;
	int	s;
	int	e;
	int	f;

	k = (int)((cub->p_x + cos(cub->th) * S_P + 3) / S_C);
	s = (int)((cub->p_y + sin(cub->th) * S_P + 3) / S_C);
	e = (int)((cub->p_x + cos(cub->th) * S_P - 3) / S_C);
	f = (int)((cub->p_y + sin(cub->th) * S_P - 3) / S_C);
	if (cub->p[s][k] != '1' && cub->p[f][e] != '1')
		return (1);
	return (0);
}
int	ft_check_wall2(t_data *cub)
{
	int	k;
	int	s;
	int	e;
	int	f;

	k = (int)((cub->p_x - cos(cub->th) * S_P - 3) / S_C);
	s = (int)((cub->p_y - sin(cub->th) * S_P - 3) / S_C);
	e = (int)((cub->p_x - cos(cub->th) * S_P + 3) / S_C);
	f = (int)((cub->p_y - sin(cub->th) * S_P + 3) / S_C);
	if (cub->p[s][k] != '1' && cub->p[f][e] != '1')
		return (1);
	return (0);
}

void	min_keyhook(int keycode, t_data *cub)
{
	if (ft_check_wall1(cub))
	{
		if (keycode == 0)
		{
			cub->p_x = cub->p_x + cos(cub->th) * S_P;
			cub->p_y = cub->p_y + sin(cub->th) * S_P;
		}
		if (keycode == 13 || keycode == 126)
		{
			cub->p_x = cub->p_x + cos(cub->th) * S_P;
			cub->p_y = cub->p_y + sin(cub->th) * S_P;
		}
	}
	if (ft_check_wall2(cub) == 1)
	{
		if (keycode == 2)
		{
			cub->p_x = cub->p_x - cos(cub->th) * S_P;
			cub->p_y = cub->p_y - sin(cub->th) * S_P;
		}
		if (keycode == 1 || keycode == 125)
		{
			cub->p_x = cub->p_x - cos(cub->th) * S_P;
			cub->p_y = cub->p_y - sin(cub->th) * S_P;
		}
	}
}

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	draw_line(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;
	int		steps;
	float	xIncrement;
	float	yIncrement;
	float	x;
	float	y;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	x = p1.x;
	y = p1.y;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ff00);
		// Assuming the line color is white (0xFFFFFF)
		x += xIncrement;
		y += yIncrement;
	}
}

void	rays(t_data cub, int *t)
{
	t[2] = ray_ver(cub, t);
	t[5] = ray_hor(cub, t);
	if (t[5] - t[2] > 0)
	{
		draw_line((t_point){t[0], t[1]}, (t_point){cub.p_x, cub.p_y}, cub.mlx,
			cub.mlx_win);
		// while ((cub.p_x >= 0 && cub.p_x < t[0]) && ((cub.p_y >= 0
		// 			&& cub.p_y < t[1])))
		// {
		// 	mlx_pixel_put(cub.mlx, cub.mlx_win, cub.p_x, cub.p_y, 0x00ff00);
		// 	cub.p_x += cos(cub.th);
		// 	cub.p_y += sin(cub.th);
		// }
	}
	else
	{
		draw_line((t_point){t[3], t[4]}, (t_point){cub.p_x, cub.p_y}, cub.mlx,
			cub.mlx_win);
		// while ((cub.p_x >= 0 && cub.p_x < t[3]) && ((cub.p_y >= 0
		// 			&& cub.p_y < t[4])))
		// {
		// 	mlx_pixel_put(cub.mlx, cub.mlx_win, cub.p_x, cub.p_y, 0x00ff00);
		// 	cub.p_x += cos(cub.th);
		// 	cub.p_y += sin(cub.th);
		// }
	}
}
int	key_hook(int keycode, t_data *cub)
{
	int t[6];
	put_plyr(cub->p_x, cub->p_y, *cub, 0x000000);
	min_keyhook(keycode, cub);
	if (keycode == 124)
	{
		if (cub->th > 2 * M_PI)
			cub->th = 0;
		cub->th += 0.1;
	}
	if (keycode == 123)
	{
		if (cub->th <= 0)
			cub->th = 2 * M_PI;
		cub->th -= 0.1;
	}
	rays((*cub), t);
	put_plyr(cub->p_x, cub->p_y, *cub, 0x00ff00);
	return (0);
}