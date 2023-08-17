/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:45:12 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/13 14:13:33 by kelmouto         ###   ########.fr       */
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
int  ft_check_a(t_data *cub)
{
int	k;
	int	s;
	int	e;
	int	f;

	k = (int)((cub->p_x - cos(cub->th + M_PI /2) * S_P - 3) / S_C);
	s = (int)((cub->p_y - sin(cub->th + M_PI /2) * S_P - 3) / S_C);
	e = (int)((cub->p_x - cos(cub->th + M_PI /2) * S_P + 3) / S_C);
	f = (int)((cub->p_y - sin(cub->th + M_PI /2) * S_P + 3) / S_C);
	if (cub->p[s][k] != '1' && cub->p[f][e] != '1')
		return (1);
	return (0);
}
int  ft_check_d(t_data *cub)
{
	int	k;
	int	s;
	int	e;
	int	f;
	k = (int)((cub->p_x + cos(cub->th + M_PI /2) * S_P - 3) / S_C);
	s = (int)((cub->p_y + sin(cub->th + M_PI /2) * S_P - 3) / S_C);
	e = (int)((cub->p_x + cos(cub->th + M_PI /2) * S_P + 3) / S_C);
	f = (int)((cub->p_y + sin(cub->th + M_PI /2) * S_P + 3) / S_C);
	if (cub->p[s][k] != '1' && cub->p[f][e] != '1')
		return (1);
	return (0);
}
void	min_keyhook(int keycode, t_data *cub)
{

	if(ft_check_a(cub))
	{
		if (keycode == 97)
		{		
			
			cub->p_x = cub->p_x - cos(cub->th + M_PI / 2) *S_P;
			cub->p_y = cub->p_y - sin(cub->th + M_PI / 2) *S_P;
		}
	}
	if(ft_check_d(cub))
	{
		if (keycode == 100)
		{
			cub->p_x = cub->p_x + cos(cub->th + M_PI / 2) *S_P;
			cub->p_y = cub->p_y + sin(cub->th + M_PI / 2) *S_P;
		}
	}
	if (ft_check_wall1(cub))
	{
	
		if (keycode == 65362 || keycode == 119)
		{
			cub->p_x = cub->p_x + cos(cub->th) * S_P;
			cub->p_y = cub->p_y + sin(cub->th) * S_P;
		}
	}
	if (ft_check_wall2(cub) == 1)
	{	
		if (keycode == 115 || keycode == 65364)
		{
			cub->p_x = cub->p_x - cos(cub->th) * S_P;
			cub->p_y = cub->p_y - sin(cub->th) * S_P;
		}
	}
}



void	draw_line(t_point p1, t_point p2, t_data cub, int clr)
{
	float	dx;
	float	dy;
	int		steps;
	float	xIncrement;
	float	yIncrement;
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
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	x = p1.x;
	y = p1.y;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(&cub, x , y , clr);
		//mlx_pixel_put(cub.mlx, cub.mlx_win, x, y, clr);
		x += xIncrement;
		y += yIncrement;
		i++;
	}
}

void	rays(t_data cub, double *t, int clr)
{

	t[2] = ray_ver(cub, t);
	t[5] = ray_hor(cub, t);
	if (t[5] - t[2] > 0)
	{
		// if( t[1] > 100)
		//	printf("\33[1;31mx1 : %d y1: %d dest %f | %f tan: %.20f\33[1;0m\n",(int)t[0],(int)t[1], t[2], t[5], cub.th );
		draw_line((t_point){t[0], t[1]}, (t_point){cub.p_x, cub.p_y}, cub, clr);
	}
	else
	{
		// if(t[4] > 100)
		//	printf(" x2 : %d y2: %d dest %f | %f tan: %f\n",(int)t[3],(int)t[4],t[5], t[3], cub.th* 180 / M_PI);
		draw_line((t_point){t[3], t[4]}, (t_point){cub.p_x, cub.p_y}, cub, clr);
	}
}

void	func(t_data cub, int clr)
{
	int i;
	double angle_step = (M_PI / 3) / cub.w; 
	i = 0;
	while(i < cub.w / 2)
	{
		cub.th -= angle_step;
		if(cub.th < 0)
			cub.th = 2* M_PI;
		i++;
	}
	i = 0;
	while (i < cub.w)
	{
		
		rays((cub), cub.t, clr);
		cub.th += angle_step;
		if(cub.th > 2 *M_PI)
			cub.th = 0;
		i++;
	}
}

int	key_hook(int keycode, t_data *cub)
{
	put_plyr(cub->p_x, cub->p_y, *cub, 0x000000);
	func(*cub, 0x000000);
	min_keyhook(keycode, cub);
	
	
	if (keycode == 65363)
	{
		cub->th += 0.05;
		if(cub->th > 2 *M_PI)
			cub->th = 0;
	}
	if (keycode == 65361)
	{	
		cub->th -= 0.05;
		if(cub->th < 0)
			cub->th = 2 *M_PI;
	}
	if(keycode == 65307)
		exit(0);
	put_plyr(cub->p_x, cub->p_y, *cub, 0x00ff00);
	func(*cub, 0x00ff00);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	return (0);
}