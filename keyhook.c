/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:45:12 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/09 16:03:29 by kelmouto         ###   ########.fr       */
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

// typedef struct s_point
// {
// 	int	x;
// 	int	y;
// }		t_point;

// void	draw_line(t_point p1, t_point p2, t_data cub, int clr)
// {
// 	int		dx;
// 	int		dy;
// 	int		steps;
// 	float	xIncrement;
// 	float	yIncrement;
// 	float	x;
// 	float	y;

// 	dx = p2.x - p1.x;
// 	dy = p2.y - p1.y;
// 	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
// 	xIncrement = dx / (float)steps;
// 	yIncrement = dy / (float)steps;
// 	x = p1.x;
// 	y = p1.y;
// 	for (int i = 0; i <= steps; i++)
// 	{
// 		mlx_pixel_put(cub.mlx, cub.mlx_win, x, y, clr);
// 		x += xIncrement;
// 		y += yIncrement;
// 	}
// }
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	draw_line(t_point p1, t_point p2, t_data cub, int clr)
{
	int		dx;
	int		dy;
	int		steps;
	float	xIncrement;
	float	yIncrement;
	float	x;
	float	y;
	int		i;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dx) > abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	if (steps == 0)
		return ;
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	x = p1.x;
	y = p1.y;
	i = 0;
	while (i <= steps)
	{
		mlx_pixel_put(cub.mlx, cub.mlx_win, x, y, clr);
		x += xIncrement;
		y += yIncrement;
		i++;
	}
}

void	rays(t_data cub, int *t, int clr)
{
	t[2] = ray_ver(cub, t);
	t[5] = ray_hor(cub, t);
	if (t[5] - t[2] > 0)
		draw_line((t_point){t[0], t[1]}, (t_point){cub.p_x, cub.p_y}, cub, clr);
	else
		draw_line((t_point){t[3], t[4]}, (t_point){cub.p_x, cub.p_y}, cub, clr);
}

void	func(t_data cub, int clr)
{
	int	i;

	i = 0;
	while (i < cub.w / 2)
	{
		cub.th -= (M_PI / 3) / cub.w;
		if (cub.th - ((M_PI / 3) / cub.w) < 0)
			cub.th = 2 * M_PI;
		i++;
	}
	i = 0;
	while (i < cub.w)
	{
		printf(" %f\n", cub.th);
		rays((cub), cub.t, clr);
		cub.th += (M_PI / 3) / cub.w;
		if (cub.th + ((M_PI / 3) / cub.w) > 2 * M_PI)
			cub.th = 0;
		i++;
	}
}

int	key_hook(int keycode, t_data *cub)
{
	put_plyr(cub->p_x, cub->p_y, *cub, 0x000000);
	func(*cub, 0x000000);
	min_keyhook(keycode, cub);
	if (keycode == 124)
	{
		if (cub->th + 0.1 > 2 * M_PI)
			cub->th = 0;
		else
			cub->th += 0.1;
	}
	if (keycode == 123)
	{
		if (cub->th - 0.1 < 0)
			cub->th = 2 * M_PI;

		else
			cub->th -= 0.1;
	}

	put_plyr(cub->p_x, cub->p_y, *cub, 0x00ff00);
	func(*cub, 0x00ff00);
	return (0);
}