/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:56:44 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/18 23:04:39 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	dist_walls(t_data cub)
{
	double		d_w;
	double		h;
	double		v;

	h = cub.t[5];
	v = cub.t[2];

	if (h > v)
	{
		d_w = fabs((S_C * cub.w) / (2 * v * tan(M_PI / 6)));
			// printf("yes%f\n", v);
	}
	else
	{
		d_w = fabs((S_C * cub.w) / (2 * h * tan(M_PI / 6)));
			// printf("no%f\n", h);
	}
	return (d_w);
}
