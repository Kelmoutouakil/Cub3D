/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:56:44 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 17:46:30 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	limit_protec(t_data cub, double r_x, double r_y)
{
	(r_y > cub.h) && (r_y = cub.h - S_C);
	(r_x > cub.w) && (r_x = cub.w - S_C);
	(r_x < 0) && (r_x = 0);
	(r_y < 0) && (r_y = 0);
	cub.t[0] = r_x;
	cub.t[1] = r_y;
}

void	limit_prot_hor(t_data cub, double r_x, double r_y)
{
	(r_y > cub.h) && (r_y = cub.h - S_C);
	(r_x > cub.w) && (r_x = cub.w - S_C);
	(r_x < 0) && (r_x = 0);
	(r_y < 0) && (r_y = 0);
	cub.t[3] = r_x;
	cub.t[4] = r_y;
}

double	dist_walls(t_data cub)
{
	double	d_w;
	double	h;
	double	v;

	h = cub.t[5];
	v = cub.t[2];
	if (h > v)
	{
		d_w = fabs((S_C * cub.w) / (2 * v * tan(M_PI / 6)));
	}
	else
	{
		d_w = fabs((S_C * cub.w) / (2 * h * tan(M_PI / 6)));
	}
	return (d_w);
}
