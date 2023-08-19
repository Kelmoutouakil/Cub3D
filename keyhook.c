/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:56:37 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 18:07:36 by kelmouto         ###   ########.fr       */
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

void	w_a_key_conditions(int keycode, t_data *cub)
{
	if (ft_check_a(cub) && (keycode == 97))
	{
		cub->p_x = cub->p_x - cos(cub->th + M_PI / 2) * S_P;
		cub->p_y = cub->p_y - sin(cub->th + M_PI / 2) * S_P;
	}
	if (ft_check_d(cub) && keycode == 100)
	{
		cub->p_x = cub->p_x + cos(cub->th + M_PI / 2) * S_P;
		cub->p_y = cub->p_y + sin(cub->th + M_PI / 2) * S_P;
	}
}

void	min_keyhook(int keycode, t_data *cub)
{
	w_a_key_conditions(keycode, cub);
	if (ft_check_wall1(cub) && (keycode == 65362 || keycode == 119))
	{
		cub->p_x = cub->p_x + cos(cub->th) * S_P;
		cub->p_y = cub->p_y + sin(cub->th) * S_P;
	}
	if (ft_check_wall2(cub) == 1 && (keycode == 115 || keycode == 65364))
	{
		cub->p_x = cub->p_x - cos(cub->th) * S_P;
		cub->p_y = cub->p_y - sin(cub->th) * S_P;
	}
}

int	key_hook(int keycode, t_data *cub)
{
	cub->ang = cub->th;
	func_rays(*cub, 0x000000);
	min_keyhook(keycode, cub);
	if (keycode == 65363)
	{
		cub->th += 0.05;
		if (cub->th > 2 * M_PI)
			cub->th = 0;
	}
	if (keycode == 65361)
	{
		cub->th -= 0.05;
		if (cub->th < 0)
			cub->th = 2 * M_PI;
	}
	if (keycode == 65307)
		exit(0);
	cub->ang = cub->th;
	func_rays(*cub, 0x87CEFA);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	return (0);
}
