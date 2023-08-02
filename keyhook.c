/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:45:12 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/02 09:55:33 by kelmouto         ###   ########.fr       */
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

int	key_hook(int keycode, t_data *cub)
{
	put_plyr(cub->p_x, cub->p_y, *cub, 0x000000);
	min_keyhook(keycode, cub);
	if (keycode == 124)
		cub->th += 0.1;
	if (keycode == 123)
		cub->th -= 0.1;
	ray_ver(cub);
	put_plyr(cub->p_x, cub->p_y, *cub, 0x00ff00);
	return (0);
}