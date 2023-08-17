/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:37:34 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/13 14:57:50 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ray_ver(t_data cub, double *t)
{
	double r_x, r_y, dx, dy;
	int i, j;
	dx = S_C;
	r_x = (int)(cub.p_x / S_C) * S_C;
	if (cub.th < M_PI / 2 || cub.th > 3 * M_PI / 2)
		r_x += S_C;
	if (cub.th > M_PI / 2 && cub.th < 3 * M_PI / 2)
		dx *= -1;
	dy = fabs(dx * tan(cub.th));
	r_y = cub.p_y - fabs((r_x - cub.p_x) * tan(cub.th));
	if (cub.th > 0 && cub.th < M_PI)
		r_y = cub.p_y + fabs((r_x - cub.p_x) * tan(cub.th));
	if (cub.th > M_PI)
		dy *= -1;
	i = r_x / S_C;
	if (cos(cub.th) < 0)
		i--;
	j = r_y / S_C;
	while (i > 0 && i < (ft_strlen(cub.p[0])) && (j > 0 && j < (int)(cub.h
				/ S_C)) && cub.p[j][i] != '1')
	{
		r_x += dx;
		r_y += dy;
		i = r_x / S_C;
		if (cos(cub.th) < 0)
			i--;
		j = r_y / S_C;
	}
	if (r_y > cub.h)
		r_y = cub.h - S_C;
	if (r_x > cub.w)
		r_x = cub.w - S_C;
	if (r_x < 0)
		r_x = 0;
	if (r_y < 0)
		r_y = 0;
	t[0] = r_x;
	t[1] = r_y;
	return (sqrt(pow(r_x - cub.p_x, 2) + pow(r_y - cub.p_y, 2)));
}

double	ray_hor(t_data cub, double *t)
{
	double r_x, r_y, dx, dy;
	int i, j;
	dy = S_C * (-1);
	r_y = (int)(cub.p_y / S_C) * S_C;
	if (cub.th > 0 && cub.th < M_PI)
		r_y += S_C;
	if (cub.th > 0 && cub.th < M_PI)
		dy = S_C;
	dx = fabs(dy / tan(cub.th));
	r_x = cub.p_x + fabs((r_y - cub.p_y) / tan(cub.th));
	// 	if(fabs(r_x)  > sqrt(pow(cub.h,2) + pow(cub.w,2)))
	// {
	// 		int s  = ray_ver(cub,t);
	// return(s + 2);
	// 	}
	if (cub.th > M_PI / 2 && cub.th < 3 * M_PI / 2)
		r_x = cub.p_x - fabs((r_y - cub.p_y) / tan(cub.th));
	if (cub.th > M_PI / 2 && cub.th < 3 * M_PI / 2)
		dx *= -1;
	i = r_x / S_C;
	j = r_y / S_C;
	if (sin(cub.th) < 0)
		j--;
	while ((i > 0 && i < ft_strlen(cub.p[0])) && (j > 0 && j < (int)(cub.h
				/ S_C)) && (cub.p[j][i] != '1'))
	{
		r_x += dx;
		r_y += dy;
		i = r_x / S_C;
		j = r_y / S_C;
		if (sin(cub.th) < 0)
			j--;
	}
	if (r_y > cub.h)
		r_y = cub.h - S_C;
	if (r_x > cub.w)
		r_x = cub.w - S_C;
	if (r_x < 0)
		r_x = 0;
	if (r_y < 0)
		r_y = 0;
	t[3] = r_x;
	t[4] = r_y;
	return (sqrt(pow(r_x - cub.p_x, 2) + pow(r_y - cub.p_y, 2)));
}

// double	ray_ver(t_data cub, double *t)
// {
// 	int	tmp;

// 	double r_x, r_y, dx, dy;
// 	int i, j;
// 	tmp = (int)(cub.p_x / S_C) * S_C;
// 	if (cos(cub.th) > 0)
// 			r_x = tmp + S_C;
// 	else
// 		r_x = tmp;
// 	dx = fabs(r_x - cub.p_x);
// 	dy = fabs(dx * tan(cub.th));
// 	r_y = cub.p_y + dy;
// 	if (sin(cub.th) < 0)
// 		r_y = fabs(cub.p_y - dy);
// 	dy = fabs(S_C * tan(cub.th));
// 	if (sin(cub.th) < 0)
// 		dy *= -1;
// 	dx = S_C;
// 	if (cos(cub.th) < 0)
// 		dx *= -1;
// 	i = r_x / S_C;
// 	if (cos(cub.th) < 0)
// 		i--;
// 	j = r_y / S_C;
// 	while (i > 0 && i < (ft_strlen(cub.p[0])) && (j > 0 && j < (int)(cub.h
// 				/ S_C)) && cub.p[j][i] != '1')
// 	{
// 		r_x += dx;
// 		r_y += dy;
// 		i = r_x / S_C;
// 		if (cos(cub.th) < 0)
// 			i--;
// 		j = r_y / S_C;
// 	}

// 	//printf("step_y = %f   angle = %.20f\n", dy,tan(cub.th));
// 	t[0] = r_x;
// 	t[1] = r_y;
// 	return (sqrt(pow(r_x - cub.p_x, 2) + pow(r_y - cub.p_y, 2)));
// }

// double 	ray_hor(t_data cub, double *t)
// {

// 	int	tmp;

// 	double r_x, r_y, dx, dy;
// 	int i, j;
// 	tmp = (int)(cub.p_y / S_C) * S_C;
// 	if (sin(cub.th)> 0)
// 		r_y = tmp + S_C;
// 	else
// 		r_y = tmp;
// 	dy = fabs(r_y - cub.p_y);
// 	dx = fabs(dy / tan(cub.th));
// 	r_x = cub.p_x + dx;

// 	if (cos(cub.th) < 0)
// 		r_x = fabs(cub.p_x - dx);
// 	dx = fabs(S_C / tan(cub.th));
// 	if (cos(cub.th) < 0)
// 		dx *= -1;
// 	dy = S_C;
// 	if (sin(cub.th) < 0)
// 		dy *= -1;
// 	i = r_x / S_C;
// 	j = r_y / S_C;
// 	if (sin(cub.th) < 0)
// 		j--;

// 	while ((i > 0 && i < ft_strlen(cub.p[0])) && (j > 0 && j < (int)(cub.h
// 				/ S_C)) && (cub.p[j][i] != '1'))
// 	{
// 		r_x += dx;
// 		r_y += dy;
// 		i = r_x / S_C;
// 		j = r_y / S_C;
// 		if (sin(cub.th) < 0)
// 			j--;
// 	}
// 	if(r_y > cub.h)
// 		r_y = cub.h - S_C;
// 	if(r_x > cub.w)
// 		r_x = cub.w - S_C;
// 	if(r_x < 0)
// 		r_x = 0;
// 	if(r_y < 0)
// 		r_y = 0;
// 	t[3] = (int)r_x;
// 	t[4] = (int)r_y;
// 	//printf("before t3 : %d t4 : %d\n",t[3],t[4]);
// 	return (sqrt(pow(r_x - cub.p_x, 2) + pow(r_y - cub.p_y, 2)));
// }
