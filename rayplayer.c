/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:37:34 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 17:59:19 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	utils_w_v(t_data cub, int *i, int *j, double *d)
{
	d[2] += d[0];
	d[3] += d[1];
	*i = d[2] / S_C;
	if (cos(cub.th) < 0)
		(*i)--;
	*j = d[3] / S_C;
}

void	utils_w_h(t_data cub, int *i, int *j, double *d)
{
	d[2] += d[0];
	d[3] += d[1];
	*i = d[2] / S_C;
	*j = d[3] / S_C;
	if (sin(cub.th) < 0)
		(*j)--;
}

double	ray_ver(t_data cub)
{
	double	d[4];
	int		i;
	int		j;

	d[0] = S_C;
	d[2] = (int)(cub.p_x / S_C) * S_C;
	(cub.th < M_PI / 2 || cub.th > 3 * M_PI / 2) && (d[2] += S_C);
	(cub.th > M_PI / 2 && cub.th < 3 * M_PI / 2) && (d[0] *= -1);
	d[1] = fabs(d[0] * tan(cub.th));
	d[3] = cub.p_y - fabs((d[2] - cub.p_x) * tan(cub.th));
	if (cub.th > 0 && cub.th < M_PI)
		(d[3] = cub.p_y + fabs((d[2] - cub.p_x) * tan(cub.th)));
	(cub.th > M_PI) && (d[1] *= -1);
	i = d[2] / S_C;
	(cos(cub.th) < 0) && (i--);
	j = d[3] / S_C;
	while (i > 0 && i < (ft_strlen(cub.p[0])) && (j > 0 && j < (int)(cub.h
				/ S_C)) && cub.p[j][i] != '1')
		utils_w_v(cub, &i, &j, d);
	limit_protec(cub, d[2], d[3]);
	return (sqrt(pow(d[2] - cub.p_x, 2) + pow(d[3] - cub.p_y, 2)));
}

double	ray_hor(t_data cub)
{
	double	d[4];
	int		i;
	int		j;

	d[1] = S_C * (-1);
	d[3] = (int)(cub.p_y / S_C) * S_C;
	if (cub.th > 0 && cub.th < M_PI)
		d[3] += S_C;
	if (cub.th > 0 && cub.th < M_PI)
		d[1] = S_C;
	d[0] = fabs(d[1] / tan(cub.th));
	d[2] = cub.p_x + fabs((d[3] - cub.p_y) / tan(cub.th));
	if (cub.th > M_PI / 2 && cub.th < 3 * M_PI / 2)
		d[2] = cub.p_x - fabs((d[3] - cub.p_y) / tan(cub.th));
	if (cub.th > M_PI / 2 && cub.th < 3 * M_PI / 2)
		d[0] *= -1;
	i = d[2] / S_C;
	j = d[3] / S_C;
	if (sin(cub.th) < 0)
		j--;
	while ((i > 0 && i < ft_strlen(cub.p[0])) && (j > 0 && j < (int)(cub.h
				/ S_C)) && (cub.p[j][i] != '1'))
		utils_w_h(cub, &i, &j, d);
	limit_prot_hor(cub, d[2], d[3]);
	return (sqrt(pow(d[2] - cub.p_x, 2) + pow(d[3] - cub.p_y, 2)));
}
